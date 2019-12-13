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
	double broj;
	Pozicija next;
};
int Push(double, Pozicija);
double PopS(Pozicija);
//int PopR(Pozicija);
int UnosIzDat(Pozicija, char*);
int main()
{
	char *fileName = NULL;
	double rez = 0;
	struct lista head;
	head.next = NULL;
	fileName = (char*)malloc(MAX_STR_LEN * sizeof(char));
	memset(fileName, '\0', MAX_STR_LEN);

	printf("Unesi ime filea: ");
	scanf("%s", fileName);

	if (strrchr(fileName, '.') == NULL)
		strcat(fileName, ".txt");

	UnosIzDat(&head, fileName);
	rez = PopS(&head);

	return 0;
}
int Push(double Rbroj, Pozicija p)
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
double PopS(Pozicija p)
{
	double broj = 0;
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
int UnosIzDat(Pozicija p, char *fName)
{
	FILE *fp = NULL;
	char* str = NULL;
	double x = 0, y = 0, br = 0;
	int numB = 0;
	str = (char*)malloc(MAX_STR_LEN * sizeof(char));
	fp = fopen(fName, "r");
	fgets(str, MAX_STR_LEN, fp);
	while (!feof(fp))
	{
		sscanf(str, " %lf %n", &br, &numB);
		if (sscanf)
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
	fclose(fp);
	return 0;
}
