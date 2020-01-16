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
	P->Ime = ime;
	printf("Unesite prezime osobe: ");
	scanf("%s", prezime);
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
	if (Tab->hashListe[kljuc] == NULL)
		Tab->hashListe[kljuc] = P;
	else
	{
		if (strcmp(P->prezime, Tab->hashListe[kljuc]->prezime) < 0)
		{
			P->next = Tab->hashListe[kljuc];
			Tab->hashListe[kljuc] = P;
		}
		else if (strcmp(P->prezime, Tab->hashListe[kljuc]->prezime))
		{

		}
	}
	return 0;
}
