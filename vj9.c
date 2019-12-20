#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<time.h>
#include"stdbool.h"
#define MAX_STR_LEN 100
struct binTree;
typedef struct binTree *Pos;
struct binTree
{
	int Num;
	Pos left;
	Pos right;
};
Pos unos(Pos, int);
Pos ispis(Pos);
Pos brisi(Pos, int);
Pos trazi(Pos, int);
int main()
{

	return 0;
}
Pos unos(Pos p, int br)
{
	if (p == NULL)
	{
		p = (Pos)malloc(sizeof(struct binTree));
		p->Num = br;
		p->left = NULL;
		p->right = NULL;
	}
	else if (p->Num > br)
		p->left = unos(p->left, br);
	else if (p->Num < br)
		p->right = unos(p->right, br);
	return p;
}
Pos ispis(Pos p)
{
	if (p != NULL)
	{
		printf("%d ", p->Num);
		ispis(p->left);
		ispis(p->right);
	}
	return NULL;
}
Pos trazi(Pos p, int br)
{
	if(p=)
}
Pos brisi(Pos p,int br)
