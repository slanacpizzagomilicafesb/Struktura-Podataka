#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define MAX_STR_LEN 100

struct polinom;
typedef struct polinom * Pozicija;

struct polinom {
	int koeficijent;
	int eksponent;
	Pozicija next;
};

int UnosIzDatoteke(Pozicija, Pozicija, char*);
int ZbrojPolinoma(Pozicija, Pozicija, Pozicija);
int UmnozakPolinoma(Pozicija, Pozicija, Pozicija);

int main()
{
	struct polinom Head1, Head2, Suma, Umnozak;
	Head1.next = NULL;
	Head2.next = NULL;
	Suma.next = NULL;
	Umnozak.next = NULL;
	char* fileName = NULL;

	fileName = (char*)malloc(MAX_STR_LEN * sizeof(char));
	if (fileName == NULL) return -1;

	UnosIzDatoteke(&Head1, &Head2, fileName);
	ZbrojPolinoma(&Head1, &Head2, &Suma);
	UmnozakPolinoma(&Head1, &Head2, &Umnozak);

	return 0;
}

int UnosIzDatoteke(Pozicija P1, Pozicija P2, char* imeDatoteke)
{
	char smece1 = '0', smece2 = '0', smece3 = '0';
	Pozicija q = NULL, q2 = NULL, temp1 = P1, temp2 = P2;
	FILE* fp = NULL;
	fp = fopen(imeDatoteke, "r");
	if (fp == NULL) return -1;
	q = (Pozicija)malloc(sizeof(struct polinom));
	if (q == NULL) return -2;

	while (smece3 != '\n' || P1 != temp1)
	{
		if (P1 == temp1)
		{
			fscanf(fp, "%d%c%c%d%c", &q->koeficijent, &smece1, &smece2, &q->eksponent, &smece3);
		}
		if (q->eksponent == P1->next->eksponent)
		{
			P1->next->koeficijent += q->koeficijent;
		}
		else if ((q->eksponent < P1->next->eksponent) || P1->next == NULL)
		{
			q->next = P1->next;
			P1->next = q;
			P1 = temp1;
			q = (Pozicija)malloc(sizeof(struct polinom));
		}
		else if (q->eksponent > P1->next->eksponent)
		{
			P1 = P1->next;
		}
	}

	while (!feof(fp) || P2 != temp2)
	{
		if (P2 == temp2)
		{
			fscanf(fp, "%d%c%c%d ", &q->koeficijent, &smece1, &smece2, &q->eksponent);
		}
		if (q->eksponent == P2->next->eksponent)
		{
			P2->next->koeficijent += q->koeficijent;
		}
		else if ((q->eksponent < P2->next->eksponent) || P2->next == NULL)
		{
			q->next = P2->next;
			P2->next = q;
			P2 = temp2;
			if (!feof(fp)) q = (Pozicija)malloc(sizeof(struct polinom));
		}
		else if (q->eksponent > P2->next->eksponent)
		{
			P2 = P2->next;
		}
	}

	fclose(fp);

	return 0;
}

int ZbrojPolinoma(Pozicija P1, Pozicija P2, Pozicija S)
{
	Pozicija q = NULL;
	q = (Pozicija)malloc(sizeof(struct polinom));
	if (q == NULL) return -1;

	P1 = P1->next;
	P2 = P2->next;

	while (P1 != NULL && P2 != NULL)
	{
		if (P1->eksponent == P2->eksponent)
		{
			q->eksponent = P1->eksponent;
			q->koeficijent = P1->koeficijent + P2->koeficijent;
			q->next = S->next;
			S->next = q;
			P1 = P1->next;
			P2 = P2->next;
			S = S->next;
			q = (Pozicija)malloc(sizeof(struct polinom));
		}
		else if (P1->eksponent < P2->eksponent)
		{
			q->eksponent = P1->eksponent;
			q->koeficijent = P1->koeficijent;
			q->next = S->next;
			S->next = q;
			P1 = P1->next;
			S = S->next;
			q = (Pozicija)malloc(sizeof(struct polinom));
		}
		else if (P2->eksponent < P1->eksponent)
		{
			q->eksponent = P2->eksponent;
			q->koeficijent = P1->koeficijent;
			q->next = S->next;
			S->next = q;
			P2 = P2->next;
			S = S->next;
			q = (Pozicija)malloc(sizeof(struct polinom));
		}
	}

	return 0;
}

/*int UmnozakPolinoma(Pozicija P1, Pozicija P2, Pozicija U)
{
	Pozicija q = NULL;
	q = (Pozicija)malloc(sizeof(struct polinom));
	if (q == NULL) return -1;

	P1 = P1->next;
	P2 = P2->next;

	while (P1 != NULL && P2 != NULL)
	{
		if (P1->eksponent == P2->eksponent)
		{
			q->eksponent = P1->eksponent;
			q->koeficijent = P1->koeficijent * P2->koeficijent;
			q->next = U->next;
			U->next = q;
			U = U->next;
			P1 = P1->next;
			P2 = P2->next;
			q = (Pozicija)malloc(sizeof(struct polinom));
		}
		else if (P1->eksponent < P2->eksponent)
		{
			P1 = P1->next;
		}
		else if (P2->eksponent < P1->eksponent)
		{
			P2 = P2->next;
		}
	}

	return 0;
}*/
