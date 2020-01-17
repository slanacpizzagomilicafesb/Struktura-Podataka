#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<time.h>
#include<ctype.h>
#define MAX_STR_LEN 100

struct cvorListe;
typedef struct cvorListe *Pozicija;
typedef struct cvorListe *Lista;
struct hashT;
typedef struct hashT *hashTab;

struct cvorListe {
	char* Ime;
	char* prezime;
	int MatBroj;
	Pozicija next;
};

struct hashT {
	int velTab;
	Lista *hashListe;
};

int Unos(Pozicija);
hashTab InitTab(int velTab);
int Hash1(Pozicija, int);
int UnosUTab(Pozicija, int, hashTab);
int Ispis(hashTab);

int main()
{
	int broj = 0, kljuc = 0;
	Pozicija* Element;



	Element = (Pozicija*)malloc(sizeof(struct cvorListe)*broj);

	return 0;
}

hashTab InitTab(int velTab)
{
	int i = 0;
	hashTab Tablica;

	Tablica = (hashTab)malloc(sizeof(struct hashT));

	Tablica->velTab = velTab;
	Tablica->hashListe = (Lista*)malloc(sizeof(Lista)*Tablica->velTab);

	for (i = 0; i < Tablica->velTab; i++)
	{
		Tablica->hashListe[i] = NULL;
	}

	return Tablica;
}

int Unos(Pozicija P)
{
	int maticniBroj = 0;
	char *ime, *prezime;

	ime = (char*)malloc(sizeof(char)*MAX_STR_LEN);
	prezime = (char*)malloc(sizeof(char)*MAX_STR_LEN);

	printf("Unesite ime osobe: ");
	scanf("%s", ime);
	P->Ime = (char*)malloc(sizeof(char)*strlen(ime));
	P->Ime = ime;
	printf("Unesite prezime osobe: ");
	scanf("%s", prezime);
	P->prezime = (char*)malloc(sizeof(char)*strlen(prezime));
	P->prezime = prezime;
	printf("Unesite maticni broj osobe: ");
	scanf("&d", &maticniBroj);
	P->MatBroj = maticniBroj;

	return 0;
}

int Hash1(Pozicija P, int velTab)
{
	int kljuc = 0;

	kljuc = P->prezime[0] + P->prezime[1] + P->prezime[2] + P->prezime[3] + P->prezime[4];
	kljuc = kljuc % velTab;

	return kljuc;
}

int UnosUTab(Pozicija P, int kljuc, hashTab Tab)
{
	Lista temp1 = NULL, temp2 = NULL;
	temp1 = Tab->hashListe[kljuc];
	if (Tab->hashListe[kljuc] == NULL)
	{
		Tab->hashListe[kljuc] = P;
		return 0;
	}

	if (strcmp(P->prezime, temp1->prezime) < 0)
	{
		P->next = temp1;
		temp1 = P;
		return 0;
	}

	temp2 = temp1->next;
	while (temp2 != NULL)
	{
		if (strcmp(P->prezime, temp2->prezime) < 0)
		{
			P->next = temp2;
			temp1->next = P;
			return 0;
		}
		else if(strcmp(P->prezime, temp2->prezime) > 0)
		{
			temp2 = temp2->next;
			temp1 = temp1->next;
		}
		else
		{
			while (temp2 != NULL)
			{
				if (strcmp(P->Ime, temp2->Ime) <= 0)
				{
					P->next = temp2;
					temp1->next = P;
					return 0;
				}
				else
				{
					temp2 = temp2->next;
					temp1 = temp1->next;
				}
			}
		}
	}
	temp1->next = P;
	return 0;
}

int Ispis(hashTab Tab)
{
	int i = 0, matBr = 0;
	Lista temp = NULL;

	for (i = 0; i < Tab->velTab; i++)
	{
		temp = Tab->hashListe[i];
		printf("Kljuc: %d\n", i);
		while (temp != NULL)
		{
			printf("\tIme: %s\n", temp->Ime);
			printf("\tPrezime: %s\n", temp->prezime);
			printf("\tZelite li ispisat maticni broj?\n\t\t1.Da\n\t\t2.Ne\n");
			scanf("%d", &matBr);
			switch (matBr)
			{
			case 1:
				printf("\tMaticni broj: %d\n", temp->MatBroj);
				break;
			default:
				break;
			}
			temp = temp->next;
		}
	}

	return 0;
}
