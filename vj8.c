#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<time.h>
#define MAX_STR_LEN 100

struct list;
typedef struct list * Position;

struct list {
	Position adress;
	Position next;
};

struct direc;
typedef struct direc * Family;

struct direc {
	Family sibling;
	Family child;
	char * Name;
};

int Push(Family, Position);
Position Pop(Position);
Family cd_dir(Family, Position, char*);

int main()
{
	int a;

	return 0;
}

int Push(Family current, Position p)
{
	Position q = NULL;
	q = (Position)malloc(sizeof(struct list));
	if (q == NULL)
		return -1;
	q->adress = current;
	q->next = p->next;
	p->next = q;

	return 0;
}
Position Pop(Position p)
{
	Family current =NULL;
	Position temp = p->next;
	current = p->next->adress;
	p->next = temp->next;
	free(temp);
	return current;
}

Family cd_dir(Family current, Position stog, char* name)
{
	Push(current, stog);
	current = current->child;
	while (current && name != current->Name)
		current = current->sibling;
	if (current == NULL)
		return -1;
	return current;
}

