#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<time.h>
#define MAX_STR_LEN 100

struct lista;
typedef struct lista * Pozicija;

struct lista {
	int broj;
	Pozicija next;
};
int Push(int, Pozicija);
int PopS(Pozicija);
//int PopR(Pozicija);
int UnosIzDat(Pozicija, char*);
int main()
{
	char *fileName = NULL;
	int rez = 0;
	struct lista head;
	head.next = NULL;
	fileName = (char*)malloc(MAX_STR_LEN * sizeof(char));

	UnosIzDat(&head, fileName);
	rez = PopS(&head);

	return 0;
}
int Push(int Rbroj, Pozicija p)
{
	Pozicija q = NULL;
	q = (Pozicija)malloc(sizeof(struct lista));
	if (q == NULL)
		return -1;
	q->broj = Rbroj;
	q->next = p->next;
	p->next = q;

	return 0;
}
int PopS(Pozicija p)
{
	int broj = 0;
	Pozicija temp = p->next;
	broj = p->next->broj;
	p->next = temp->next;
	free(temp);
	return broj;
}
/*int PopR(Pozicija p)
{
	int broj = 0;
	Pozicija temp = NULL;
	while (p->next->next != NULL)
		p = p->next;
	temp = p->next;
	broj = p->next->broj;
	p->next = temp->next;
	free(temp);
	return broj;
}*/
int UnosIzDat(Pozicija p, char *fileName)
{
	FILE *fp = NULL;
	char* str = NULL;
	int x = 0, y = 0, br = 0, numB = 0;
	str = (char*)malloc(MAX_STR_LEN * sizeof(char));
	fp = fopen(fileName, "r");
	fgets(str, MAX_STR_LEN, fp);
	while (!feof(fp))
	{
		sscanf(str, " %d %n", &br, &numB);
		if (sscanf == 1)
		{
			Push(x, p);
			str += numB;
		}
		else
		{
			x = PopS(p);
			y = PopS(p);
			switch (*str)
			{
			case '+':
				Push(y + x, p);
				break;
			case '*':
				Push(y * x, p);
				break;
			case '-':
				Push(y - x, p);
				break;
			}
			str++;
		}
	}
	return 0;
}
