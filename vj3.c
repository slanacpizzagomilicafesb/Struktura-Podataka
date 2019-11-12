#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_DULJINA_CHARA 100

struct osoba;
typedef struct osoba * Pozicija;

struct osoba {
	char ime_s[15];
	char prezime_s[15];
	int g_rodenja;
	Pozicija next;
};

int UnosImena(char*);
int UnosPrezimena(char*);
int UnosGodine();

int UnosNaPocetak(char*, char*, int, Pozicija);
int IspisListe(Pozicija);
int UnosNaKraj(char*, char*, int, Pozicija);
Pozicija PronadiElement(char*, Pozicija);
Pozicija NadiPrethodnog(char*, char*, int, Pozicija);
Pozicija NadiZadnjiElement(Pozicija);
int Brisi(char*, char*, int, Pozicija);
int UnosIza(char*, char*, int, char*, char*, int, Pozicija);
int UnosIspred(char*, char*, int, char*, char*, int, Pozicija);
int SortiraniUnos(char*, char*, int, Pozicija);
int IspisUDatoteku(Pozicija, const char*);
int UnosIzDatoteke(Pozicija, const char*);

int main()
{
	struct osoba Head;
	Head.next = NULL;
	char *ime = NULL, *prezime = NULL, *temp_ime = NULL, *temp_prezime = NULL;
	int godina = 0, temp_godina = 0;
	char *ime_datoteke_za_ispis = NULL, *ime_datoteke_za_unos = NULL;

	ime_datoteke_za_ispis = (char*)malloc(MAX_DULJINA_CHARA * sizeof(char));
	if (ime_datoteke_za_ispis == NULL) return -1;
	ime_datoteke_za_unos = (char*)malloc(MAX_DULJINA_CHARA * sizeof(char));
	if (ime_datoteke_za_unos == NULL) return -1;
	ime = (char*)malloc(MAX_DULJINA_CHARA * sizeof(char));
	if (ime == NULL) return -1;
	prezime = (char*)malloc(MAX_DULJINA_CHARA * sizeof(char));
	if (prezime == NULL) return -1;
	temp_ime = (char*)malloc(MAX_DULJINA_CHARA * sizeof(char));
	if (temp_ime == NULL) return -1;
	temp_prezime = (char*)malloc(MAX_DULJINA_CHARA * sizeof(char));
	if (temp_prezime == NULL) return -1;
	

	printf("Unesite podatke za osobu:\n");
	UnosImena(ime);
	UnosPrezimena(prezime);
	godina = UnosGodine();
	SortiraniUnos(ime, prezime, godina, &Head);

	printf("Unesite podatke za osobu:\n");
	UnosImena(ime);
	UnosPrezimena(prezime);
	godina = UnosGodine();
	SortiraniUnos(ime, prezime, godina, &Head);

	printf("Unesite podatke za osobu:\n");
	UnosImena(ime);
	UnosPrezimena(prezime);
	godina = UnosGodine();
	SortiraniUnos(ime, prezime, godina, &Head);

	printf("Unesite podatke za osobu:\n");
	UnosImena(ime);
	UnosPrezimena(prezime);
	godina = UnosGodine();
	SortiraniUnos(ime, prezime, godina, &Head);

	printf("Unesite podatke osobe iza koje zelite upisati osobu:\n");
	UnosImena(ime);
	UnosPrezimena(prezime);
	godina = UnosGodine();
	printf("Unesite podatke osobe koju zelite unijeti:\n");
	UnosImena(temp_ime);
	UnosPrezimena(temp_prezime);
	temp_godina = UnosGodine();
	UnosIza(ime, prezime, godina, temp_ime, temp_prezime, temp_godina, &Head);

	printf("Unesite podatke osobe ispred koje zelite upisati osobu:\n");
	UnosImena(ime);
	UnosPrezimena(prezime);
	godina = UnosGodine();
	printf("Unesite podatke osobe koju zelite unijeti:\n");
	UnosImena(temp_ime);
	UnosPrezimena(temp_prezime);
	temp_godina = UnosGodine();
	UnosIspred(ime, prezime, godina, temp_ime, temp_prezime, temp_godina, &Head);

	printf("Unesite ime datoteke u koju zelite ispisati listu: ");
	scanf("%s", ime_datoteke_za_ispis);
	strcat(ime_datoteke_za_ispis, ".txt");
	IspisUDatoteku(&Head, ime_datoteke_za_ispis);

	printf("Unesite ime datoteke iz koje zelite unosit podatke u listu: ");
	scanf("%s", ime_datoteke_za_unos);
	strcat(ime_datoteke_za_unos, ".txt");
	UnosIzDatoteke(&Head, ime_datoteke_za_unos);

	return 0;
}

int UnosImena(char* ime)
{
	printf("Ime: ");
	scanf("%s", ime);

	return 0;
}

int UnosPrezimena(char* prezime)
{
	printf("Prezime: ");
	scanf("%s", prezime);

	return 0;

}

int UnosGodine()
{
	int godina;
	printf("Godina rodenja: ");
	scanf("%d", &godina);

	return godina;
}

int UnosNaPocetak(char* ime, char* prezime, int godina, Pozicija P)
{
	Pozicija q;
	q = (Pozicija)malloc(sizeof(struct osoba));
	strcpy(q->ime_s, ime);
	strcpy(q->prezime_s, prezime);
	q->g_rodenja = godina;

	q->next = P->next;
	P->next = q;

	return 0;
}

int IspisListe(Pozicija P)
{
	printf("Ispis liste:\n");
	while (P != NULL)
	{
		printf("Ime: %s\n Prezime: %s\n Godina rodenja: %d\n\n", P->ime_s, P->prezime_s, P->g_rodenja);
		P = P->next;
	}
	return 0;
}

int UnosNaKraj(char* ime, char* prezime, int godina, Pozicija P)
{
	Pozicija q;
	q = (Pozicija)malloc(sizeof(struct osoba));
	while (P->next != NULL) P = P->next;
	q->g_rodenja = godina;
	strcpy(q->ime_s, ime);
	strcpy(q->prezime_s, prezime);

	q->next = P->next;
	P->next = q;

	return 0;
}

Pozicija PronadiElement(char* prezime, Pozicija P)
{
	while (P != NULL && !(strcmp(P->prezime_s, prezime))) P = P->next;
	if (P == NULL) return NULL;
	else return P;
}

Pozicija NadiPrethodnog(char* ime, char* prezime, int godina, Pozicija P)
{
	Pozicija pret = P;
	while (P != NULL && (!(strcmp(P->ime_s, ime)) || !(strcmp(P->prezime_s, prezime)) || (P->g_rodenja != godina)))
	{
		pret = P;
		P = P->next;
	}
	if (P == NULL) return NULL;
	else return pret;
}

int Brisi(char* ime, char* prezime, int godina, Pozicija P)
{
	Pozicija temp = NULL;
	P = NadiPrethodnog(ime, prezime, godina, P);

	if (P == NULL) printf("Nema tog elementa");
	else
	{
		temp = P->next;
		P->next = P->next->next; //temp->next;
		free(temp);
	}
	return 0;
}

int UnosIza(char* ime1, char* prezime1, int godina1, char* ime2, char* prezime2, int godina2, Pozicija P)
{
	P = P->next;
	while (P != NULL && (!(strcmp(P->ime_s, ime1)) || !(strcmp(P->prezime_s, prezime1)) || (P->g_rodenja != godina1)))
		P = P->next;
	if (P == NULL) printf("Nema tog elementa.");
	else UnosNaPocetak(ime2, prezime2, godina2, P);
	return 0;
}

int UnosIspred(char* ime1, char* prezime1, int godina1, char* ime2, char* prezime2, int godina2, Pozicija P)
{
	P = NadiPrethodnog(ime1, prezime1, godina1, P);
	if (P == NULL) printf("Nema tog elementa.");
	else UnosNaPocetak(ime2, prezime2, godina2, P);
	return 0;
}

Pozicija NadiZadnjiElement(Pozicija P)
{
	while (P->next != NULL) P = P->next;
	return P;
}

int SortiraniUnos(char* ime, char* prezime, int godina, Pozicija P)
{
	Pozicija temp = P;
	int i = 0;
	while (temp != NULL)
	{
		while (prezime[i] != '\0' && P->next->prezime_s[i] != '\0')
		{
			if (prezime[i] == P->next->prezime_s[i]) i++;
			else if (prezime[i] > P->next->prezime_s[i])
			{
				P = P->next;
				break;
			}
			else if (prezime[i] < P->next->prezime_s[i])
			{
				temp = NULL;
				break;
			}
		}
		if (prezime[i] == '\0') break;
		i = 0;
	}

	UnosNaPocetak(ime, prezime, godina, P);

	return 0;
}

int IspisUDatoteku(Pozicija P, const char* ime_datoteke)
{
	P = P->next;
	FILE* fp = NULL;
	fp = fopen(ime_datoteke, "w");
	if (fp == NULL)
	{
		printf("GRESKA!");
		return -1;
	}
	else
	{
		while (P != NULL)
		{
			fprintf(fp, "Ime: %s\n Prezime: %s\n Godina rodenja: %d\n\n", P->ime_s, P->prezime_s, P->g_rodenja);
			P = P->next;
		}
	}
	fclose(fp);
	return 0;
}

int UnosIzDatoteke(Pozicija P, const char* ime_datoteke)
{
	FILE* fp = NULL;
	Pozicija q = NULL;
	fp = fopen(ime_datoteke, "r");
	q = (Pozicija)malloc(sizeof(struct osoba));

	if (fp == NULL || q == NULL)
	{
		printf("GRESKA!");
		return -1;
	}
	else
	{
		while (P != NULL)
		{
			fscanf(fp, "%s %s %d", q->ime_s, q->prezime_s, &q->g_rodenja);
			q->next = P->next;
			P->next = q;
			q = (Pozicija)malloc(sizeof(struct osoba));
			if (q == NULL)
			{
				printf("GRENSKA!");
				return -1;
			}
		}
	}
	fclose(fp);
	return 0;
}
