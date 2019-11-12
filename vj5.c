#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define MAX_STR_LEN 100

struct lista;
typedef struct lista * Pozicija;

struct lista {
	int broj;
	Pozicija next;
};

int UnosIzDatoteke(Pozicija, Pozicija, char*);
int UnijaLista(Pozicija, Pozicija, Pozicija);
int PresjekLista(Pozicija, Pozicija, Pozicija);

int main()
{
	struct lista Head1, Head2, Unija, Presjek;
	char* ime_datoteke = NULL;
	Head1.next = NULL;
	Head2.next = NULL;
	Unija.next = NULL;
	Presjek.next = NULL;

	ime_datoteke = (char*)malloc(MAX_STR_LEN * sizeof(char));
	if (ime_datoteke == NULL) return -1;
	printf("Unesi ime datoteke: ");
	scanf("%s", ime_datoteke);
	if (strrchr(ime_datoteke, '.') == NULL)
		strcat(ime_datoteke, ".txt");

	UnosIzDatoteke(&Head1, &Head2, ime_datoteke);
	UnijaLista(&Head1, &Head2, &Unija);
	PresjekLista(&Head1, &Head2, &Presjek);

	return 0;
}

int UnosIzDatoteke(Pozicija P1, Pozicija P2, char* imeDatoteke)
{
	char smece = '0';
	Pozicija q = NULL, temp1 = P1, temp2 = P2;
	FILE* fp = NULL;
	fp = fopen(imeDatoteke, "r");
	if (fp == NULL) return -1;
	q = (Pozicija)malloc(sizeof(struct lista));
	if (q == NULL) return -2;

	while (smece != '\n' || P1 != temp1)
	{
		if (P1 == temp1)
		{
			fscanf(fp, "%d%c", &q->broj, &smece);
		}
		if (P1->next == NULL || (q->broj <= P1->next->broj))
		{
			q->next = P1->next;
			P1->next = q;
			P1 = temp1;
			q = (Pozicija)malloc(sizeof(struct lista));
		}
		else if (q->broj > P1->next->broj)
		{
			P1 = P1->next;
		}
	}

	while (!feof(fp) || P2 != temp2)
	{
		if (P2 == temp2)
		{
			fscanf(fp, "%d ", &q->broj);
		}
		if (P2->next == NULL || (q->broj <= P2->next->broj))
		{
			q->next = P2->next;
			P2->next = q;
			P2 = temp2;
			q = (Pozicija)malloc(sizeof(struct lista));
		}
		else if (q->broj > P2->next->broj)
		{
			P2 = P2->next;
		}
	}

	fclose(fp);

	return 0;
}

int UnijaLista(Pozicija P1, Pozicija P2, Pozicija U)
{
	Pozicija q = NULL;
	q = (Pozicija)malloc(sizeof(struct lista));
	if (q == NULL) return - 1;

	P1 = P1->next;
	P2 = P2->next;

	while (P1 != NULL || P2 != NULL)
	{
		if (P1 == NULL)
		{
			while (P2 != NULL)
			{
				q->broj = P2->broj;
				q->next = U->next;
				U->next = q;
				P2 = P2->next;
				q = (Pozicija)malloc(sizeof(struct lista));
			}
			break;
		}
		else if (P2 == NULL)
		{
			while (P1 != NULL)
			{
				q->broj = P1->broj;
				q->next = U->next;
				U->next = q;
				P1 = P1->next;
				q = (Pozicija)malloc(sizeof(struct lista));
			}
			break;
		}
		if (P1->broj == P2->broj)
		{
			q->broj = P1->broj;
			q->next = U->next;
			U->next = q;
			P1 = P1->next;
			P2 = P2->next;
			q = (Pozicija)malloc(sizeof(struct lista));
		}
		else if (P1->broj < P2->broj)
		{
			q->broj = P1->broj;
			q->next = U->next;
			U->next = q;
			P1 = P1->next;
			q = (Pozicija)malloc(sizeof(struct lista));
		}
		else if (P2->broj < P1->broj)
		{
			q->broj = P2->broj;
			q->next = U->next;
			U->next = q;
			P2 = P2->next;
			q = (Pozicija)malloc(sizeof(struct lista));
		}
	}
	return 0;
}

int PresjekLista(Pozicija P1, Pozicija P2, Pozicija Pr)
{
	Pozicija q = NULL;
	q = (Pozicija)malloc(sizeof(struct lista));
	if (q == NULL) return -1;

	P1 = P1->next;
	P2 = P2->next;
	while (P1 != NULL && P2 != NULL)
	{
		if (P1->broj == P2->broj)
		{
			q->broj = P1->broj;
			q->next = Pr->next;
			Pr->next = q;
			P1 = P1->next;
			P2 = P2->next;
			q = (Pozicija)malloc(sizeof(struct lista));
		}
		else if (P1->broj < P2->broj)
		{
			P1 = P1->next;
		}
		else if (P2->broj < P1->broj)
		{
			P2 = P2->next;
		}
	}
	return 0;
}
