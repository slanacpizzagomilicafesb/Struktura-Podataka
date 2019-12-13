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
	float broj;
	Pozicija next;
};
int Push(float, Pozicija);
float PopS(Pozicija);
//int PopR(Pozicija);
int UnosIzDat(Pozicija, const char*);
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
	rez = PopS(&head);

	printf("%f\n", rez);

	return 0;
}
int Push(float Rbroj, Pozicija p)
{
	Pozicija q = NULL;
	q = (Pozicija)malloc(sizeof(struct lista));
	if (q == NULL)
		return -1;
	q->broj = Rbroj;
	q->next = p->next;
	p->next = q;

	printf("%f\n", q->broj);

	return 0;
}
float PopS(Pozicija p)
{
	float broj = 0;
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
int UnosIzDat(Pozicija p, const char *fName)
{
	FILE *fp = NULL;
	char* str = NULL;
	float x = 0, y = 0, br = 0;
	int numB = 0;
	str = (char*)malloc(MAX_STR_LEN * sizeof(char));
	fp = fopen(fName, "r");
	fgets(str, MAX_STR_LEN, fp);
	printf("%s\n", str);
	while ((*str) != '\0')
	{
		if (sscanf(str, " %f%n", &br, &numB) == 1)
		{
			Push(br, p);
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
				Push(y + x, p);
				break;
			case '*':
				Push(y * x, p);
				break;
			case '-':
				Push(y - x, p);
				break;
			case '/':
				if (x != 0)
					Push(y / x, p);
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
