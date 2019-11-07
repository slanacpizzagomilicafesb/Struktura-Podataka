#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_BOD 100
#define MAX_STRLEN 100

struct _student;
typedef struct _student* pstud;
typedef struct _student _STUDENT;

struct _student {
	char ime[50];
	char prezime[50];
	int bodovi;
	double rel_bod;
};

int BrojanjeRedaka(char*);
int UcitavanjeIzDatoteke(pstud, char*);
int Ispis(pstud, char*);

int main()
{
	pstud st = NULL;
	char *ime_datoteke_za_unos = NULL;

	ime_datoteke_za_unos = (char*)malloc(MAX_STRLEN * sizeof(char));
	if (ime_datoteke_za_unos == NULL) return -1;

	printf("Unesite ime datoteke za unos: ");
	scanf("%s", ime_datoteke_za_unos);
	if (strrchr(ime_datoteke_za_unos, '.') == NULL) 
		strcat(ime_datoteke_za_unos, ".txt");

	st = (pstud)malloc(BrojanjeRedaka(ime_datoteke_za_unos) * sizeof(_STUDENT));
	if (st = NULL) return - 1;

	printf("Retci: %d\n", BrojanjeRedaka(ime_datoteke_za_unos));

	UcitavanjeIzDatoteke(st, ime_datoteke_za_unos);
	Ispis(st, ime_datoteke_za_unos);

	system("pause");
	return 0;
}

int BrojanjeRedaka(char* ime_datoteke)
{
	FILE* dat = NULL;
	int brojac = 0;
	char str[100] = { 0 };
	dat = fopen(ime_datoteke, "r");
	if (dat == NULL) return -1;
	while (!feof(dat))
	{
		fgets(str, 100, dat);
		brojac++;
	}
	fclose(dat);
	return brojac;
}

int UcitavanjeIzDatoteke(pstud st, char* ime_datoteke)
{
	int i = 0;
	FILE* dat = NULL;
	dat = fopen(ime_datoteke, "r");
	if (dat == NULL) return -1;
	while (!feof(dat))
	{
		fscanf(dat, "%s %s %d", st[i].ime, st[i].prezime, &st[i].bodovi);
		st[i].rel_bod = (double)st[i].bodovi / MAX_BOD * 100;
		i++;
	}
	fclose(dat);
	return 0;
}

int Ispis(pstud st, char* ime_datoteke)
{
	int i = 0;
	for (i = 0; i <= BrojanjeRedaka(ime_datoteke); i++)
	{
		printf("%s %s %d %lf", st[i].ime, st[i].prezime, st[i].bodovi, st[i].rel_bod);
	}
	return 0;
}
