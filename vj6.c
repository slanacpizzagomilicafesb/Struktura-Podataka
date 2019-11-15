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
	int broj;
	Pozicija next;
};
int Push (int,Pozicija);
int PopS (Pozicija);
int PopR(Pozicija);
int main ()
{
	int broj= 0;
	struct lista head;
	head.next=NULL;
	srand(time(NULL));

	Push(rand()%91+10,&head);
	broj= PopS(&head);
	printf("Stog: %d ",broj);
	Push(rand()%91+10,&head);
	broj= PopR(&head);
	printf("Red: %d ",broj);
	return 0;
}
int Push(int Rbroj,Pozicija p)
{
	Pozicija q = NULL;
	q=(Pozicija)malloc(sizeof(struct lista));
	if(q==NULL)
		return -1;
	q->broj=Rbroj;
	q->next=p->next;
	p->next=q;

	return 0;
}
int PopS( Pozicija p)
{
	int broj = 0;
	Pozicija temp = p->next;
	broj = p->next->broj;
	p->next=temp->next;
	free(temp);
	return broj;
}
int PopR( Pozicija p)
{
	int broj =0;
	Pozicija temp = NULL;
	while(p->next->next!=NULL)
		p=p->next;
	temp=p->next;
	broj=p->next->broj;
	p->next=temp->next;
	free(temp);
	return broj;
}
