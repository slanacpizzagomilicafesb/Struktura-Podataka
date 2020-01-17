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
	char Ime[MAX_STR_LEN];
	char prezime[MAX_STR_LEN];
	int MatBroj;
	Pozicija next;
};

struct hashT {
	int velTab;
	Lista hashListe[11];
};

int Unos(Pozicija, int);
hashTab InitTab(int velTab);
int Hash1(Pozicija, int);
int UnosUTab(Pozicija, int, hashTab);
int Ispis(hashTab);

int main()
{
	int broj = 0, kljuc = 0, i = 0, velTab = 0;
	Pozicija Element;
	hashTab Tab = NULL;

	printf("Velicina tablice: ");
	scanf("%d", &velTab);

	Tab = InitTab(velTab);

	printf("Koliko clanova zelite unijet: ");
	scanf("%d", &broj);

	
	for (i = 0; i < broj; i++)
	{
		Element = (Pozicija)malloc(sizeof(struct cvorListe));
		if (Element == NULL)
		{
			printf("greska pri alokacije elementa.");
			return 1;
		}
		Element->next = NULL;

		Unos(Element, i);
		kljuc = Hash1(Element, velTab);
		UnosUTab(Element, kljuc, Tab);
	}

	Ispis(Tab);

	return 0;
}

hashTab InitTab(int velTab)
{
	int i = 0;
	hashTab Tablica;

	Tablica = (hashTab)malloc(sizeof(struct hashT));

	if (Tablica == NULL)
	{
		printf("Greska pri alokaciji tablice.");
		return NULL;
	}

	Tablica->velTab = velTab;

	for (i = 0; i < Tablica->velTab; i++)
	{
		Tablica->hashListe[i] = NULL;
	}

	return Tablica;
}

int Unos(Pozicija P, int i)
{
	int maticniBroj = 0;
	char ime[MAX_STR_LEN], prezime[MAX_STR_LEN];

	printf("Unesite ime %d. osobe: ", i+1);
	scanf("%s", ime);
	strcpy(P->Ime, ime);

	printf("Unesite prezime %d. osobe: ", i+1);
	scanf("%s", prezime);
	strcpy(P->prezime, prezime);

	printf("Unesite maticni broj %d. osobe: ", i+1);
	scanf("%d", &maticniBroj);
	P->MatBroj = maticniBroj;

	printf("\n");

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
		for (temp; temp != NULL; temp = temp->next)
		{
			printf("\tIme: %s\n", temp->Ime);
			printf("\tPrezime: %s\n", temp->prezime);
			printf("\tZelite li ispisat maticni broj?\n\t1.Da\n\t2.Ne\n\t");
			scanf("%d", &matBr);
			if (matBr == 1)
				printf("\tMaticni broj: %d\n", temp->MatBroj);

		}
	}

	return 0;
}
