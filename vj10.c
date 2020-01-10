#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<time.h>
#include<ctype.h>
#define MAX_STR_LEN 100

struct binTree;
typedef struct binTree * Pos;

struct binTree {
	float broj;
	char znak;
	Pos L;
	Pos R;
};

struct lista;
typedef struct lista * Pozicija;

struct lista {
	Pos adresa;
	Pozicija next;
};



int Push(Pos, Pozicija);
Pos PopS(Pozicija);
int UnosIzDat(Pozicija, const char*);
Pos IspisUDat(Pos, const char*);

int main()
{
	char *fileName = NULL;
	int provjera = 0;
	float rez = 0;
	struct lista head;
	head.next = NULL;
	fileName = (char*)malloc(MAX_STR_LEN * sizeof(char));

	if (fileName == NULL)
	{
		printf("GRESKA pri alokaciji fileNamea! \n");
		return -1;
	}

	memset(fileName, '\0', MAX_STR_LEN);

	printf("Unesi ime filea: ");
	scanf("%s", fileName);

	if (strrchr(fileName, '.') == NULL)
		strcat(fileName, ".txt");

	provjera = UnosIzDat(&head, fileName);

	IspisUDat(PopS(&head), fileName);

	return 0;
}
int Push(Pos adr, Pozicija p)
{
	Pozicija q = NULL;
	q = (Pozicija)malloc(sizeof(struct lista));
	if (q == NULL)
		return -1;
	q->adresa = adr;
	q->next = p->next;
	p->next = q;

	return 0;
}
Pos PopS(Pozicija p)
{
	Pos adr = NULL;
	Pozicija temp = p->next;
	adr = p->next->adresa;
	p->next = temp->next;
	free(temp);
	return adr;
}

int UnosIzDat(Pozicija p, const char *fName)
{
	FILE *fp = NULL;
	Pos q = NULL, x = NULL, y = NULL;
	char* str = NULL;
	float br = 0;
	int numB = 0;
	str = (char*)malloc(MAX_STR_LEN * sizeof(char));
	fp = fopen(fName, "r");
	fgets(str, MAX_STR_LEN, fp);
	printf("%s\n", str);
	while ((*str) != '\0')
	{
		if (sscanf(str, " %f%n", &br, &numB) == 1)
		{
			q = (Pos)malloc(sizeof(struct binTree));
			q->broj = br;
			q->L = NULL;
			q->R = NULL;
			Push(q, p);
			str += numB;
		}
		else if (sscanf(str, " %f%n", &br, &numB) == 0)
		{
			x = PopS(p);
			y = PopS(p);
			str++;
			switch (*str)
			{
			case '+':
				q = (Pos)malloc(sizeof(struct binTree));
				q->znak = '+';
				q->L = y;
				q->R = x;
				Push(q, p);
				break;
			case '*':
				q = (Pos)malloc(sizeof(struct binTree));
				q->znak = '*';
				q->L = y;
				q->R = x;
				Push(q, p);
				break;
			case '-':
				q = (Pos)malloc(sizeof(struct binTree));
				q->znak = '-';
				q->L = y;
				q->R = x;
				Push(q, p);
				break;
			case '/':
				if (x != 0)
				{
					q = (Pos)malloc(sizeof(struct binTree));
					q->znak = '/';
					q->L = y;
					q->R = x;
					Push(q, p);
				}
				break;
			default:
				printf("GRESKA pri citanju! \n");
				return 1;
				break;
			}
			str++;
		}
	}
	fclose(fp);
	return 0;
}

Pos IspisUDat(Pos P, const char* fName)
{
	FILE* fp = NULL;
	fp = fopen(fName, "w");
	if (P != NULL)
	{
		IspisUDat(P->L, fName);
		if (isdigit(P->broj))
			fprintf(fp, " %f", P->broj);
		else
			fprintf(fp, " %c", P->znak);
		IspisUDat(P->R, fName);
	}
	fclose(fp);

	return NULL;
}
