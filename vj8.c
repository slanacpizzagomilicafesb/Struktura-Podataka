#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<time.h>
#include"stdbool.h"
#define MAX_STR_LEN 100

struct direc;
typedef struct direc * Family;

struct direc {
	Family sibling;
	Family child;
	char* Name;
};

struct list;
typedef struct list * Position;

struct list {
	Family adress;
	Position next;
};

int Push(Family, Position);
Family Pop(Position);
Family cd_dir(Family, Position, char*);
int dir(Family);
int md(Family, char*);
Family cd(Position);
int Unos(Family, Family, char*);
void printR(Position);

int main()
{
	int broj = 0;
	bool i = true;
	char ime[MAX_STR_LEN];
	struct list Head1;
	struct direc Head2;
	Family ptr = &Head2;
	Head2.Name = "C:";
	Head1.next = NULL;
	Head2.child = NULL;
	Head2.sibling = NULL;

	printf("Odaberite jednu od opcija (od 1 do 5):\n1.md \n2.cd dir \n3.cd.. \n4.dir \n5.izlaz \n");
	
	while (i)
	{
		
		scanf("%d", &broj);
		switch (broj)
		{
		case 1:
			printf("Unesite ime direktorija kojeg zelite napravit: ");
			scanf("%s", ime);
			printR(Head1.next);
			printf("%s: md %s\n", ptr->Name, ime);
			md(ptr, ime);
			break;
		case 2:
			printf("Unesite ime direktorija kojem zelite pristupiti: ");
			scanf("%s", ime);
			printR(Head1.next);
			printf("%s: cd dir %s\n", ptr->Name, ime);
			ptr = cd_dir(ptr, &Head1, ime);
			break;
		case 3:
			printR(Head1.next);
			printf("%s: cd..\n", ptr->Name);
			ptr = cd(&Head1);
			break;
		case 4:
			printR(Head1.next);
			printf("%s: dir\n", ptr->Name);
			dir(ptr);
			break;
		case 5:
			printR(Head1.next);
			printf("%s: izlaz\n", ptr->Name);
			i = false;
		default:
			printf("Greska pri unosu!");
			break;
		}
	}

	return 0;
}

int Unos(Family current, Family newElement, char* newName)
{
	newElement->sibling = current->sibling;
	current->sibling = newElement;
	newElement->child = NULL;
	strcat(newElement->Name, newName);
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
Family Pop(Position p)
{
	Family current = NULL;
	Position temp = p->next;
	current = p->next->adress;
	p->next = temp->next;
	free(temp);
	return current;
}

Family cd_dir(Family current, Position stog, char* name)
{
	Family temp = current;
	Push(current, stog);
	current = current->child;
	while (current && name != current->Name)
		current = current->sibling;
	if (current == NULL)
	{
		printf("Nema tog elementa.");
		return temp;
	}
	return current;
}

int dir(Family current)
{
	current = current->child;
	while (current != NULL)
	{
		printf("%s\n", current->Name);
		current = current->sibling;
	}
	return 0;
}

int md(Family current, char* newName)
{
	Family q = NULL;
	
	if ((current->child == NULL) || (strcmp(newName, current->child->Name) < 0))
	{
		
		q = (Family)malloc(sizeof(struct direc));
		if (q == NULL)
		{
			printf("Greska pri alokaciji memorije!");
			return -1;
		}
		q->sibling = current->child;
		current->child = q;
		q->child = NULL;
		strcat(q->Name, newName);

		return 0;
	}

	current = current->child;
	current = current->sibling;

	while (current->sibling != NULL)
	{
		if (strcmp(newName, current->sibling->Name) == 0)
		{
			printf("Ne mozes unit direktorij istog imena.");

		}
		else if (strcmp(newName, current->sibling->Name) < 0)
		{
			q = (Family)malloc(sizeof(struct direc));
			if (q == NULL)
			{
				printf("Greska pri alokaciji memorije!");
				return -1;
			}
			Unos(current, q, newName);
			return 0;
		}
		else
			current = current->sibling;
	}
	q = (Family)malloc(sizeof(struct direc));
	if (q == NULL)
	{
		printf("Greska pri alokaciji memorije!");
		return -1;
	}
	Unos(current, q, newName);
	return 0;
}

Family cd(Position stog)
{
	Family newElement = Pop(stog);
	return newElement;
}

void printR(Position stog)
{
	if (!stog) return;
	printR(stog->next);
	printf("%s\\", stog->adress->Name);
}
