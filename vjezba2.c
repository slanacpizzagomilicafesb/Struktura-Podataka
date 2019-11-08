#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct osoba * Pozicija;

struct osoba {
char ime_s[15];
char prezime_s[15];
int g_rodenja;
Pozicija next;
};

int UnosImena(char[]);
int UnosPrezimena(char[]);
int UnosGodine();

int UnosNaPocetak(char[], char[], int, Pozicija);
int IspisListe(Pozicija);
int UnosNaKraj(char[], char[], int, Pozicija);
Pozicija PronadiElement(char[], Pozicija);
Pozicija NadiPrethodnog(char[], char[], int, Pozicija);
int Brisi(char[], char[], int, Pozicija);

int main()
{
struct osoba Head;
Head.next = NULL;
char ime[15] = { 0 }, prezime[15] = { 0 };
int godina = 0;

printf("Unesite podatke za osobu:\n");
UnosImena(ime);
UnosPrezimena(prezime);
godina = UnosGodine();
UnosNaPocetak(ime, prezime, godina, &Head);

printf("Unesite podatke za osobu:\n");
UnosImena(ime);
UnosPrezimena(prezime);
godina = UnosGodine();
UnosNaKraj(ime, prezime, godina, &Head);

IspisListe(Head.next);

printf("Unesite prezime osobe koju zelite pronaci:\n");
UnosPrezimena(prezime);
PronadiElement(prezime, &Head);

printf("Unesite podatke osobe koju zelite izbrisati:\n");
UnosImena(ime);
UnosPrezimena(prezime);
godina = UnosGodine();
Brisi(ime, prezime, godina, &Head);

return 0;
}

int UnosImena(char ime[15])
{
printf("Ime: ");
scanf("%s", ime);

return 0;
}

int UnosPrezimena(char prezime[15])
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

int UnosNaPocetak(char ime[15], char prezime[15], int godina, Pozicija P)
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
printf("Ime: %s\n Prezime: %s\n Godina rodenja: %d\n", P->ime_s, P->prezime_s, P->g_rodenja);
P = P->next;
}
return 0;
}

int UnosNaKraj(char ime[15], char prezime[15], int godina, Pozicija P)
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

Pozicija PronadiElement(char prezime[15], Pozicija P)
{
while (P != NULL && !(strcmp(P->prezime_s, prezime))) P = P->next;
if (P == NULL) return NULL;
else return P;
}

Pozicija NadiPrethodnog(char ime[15], char prezime[15], int godina, Pozicija P)
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

int Brisi(char ime[15], char prezime[15], int godina, Pozicija P)
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
