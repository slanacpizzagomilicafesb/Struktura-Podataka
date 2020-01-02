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
Pos traziMin(Pos);

int main()
{
	struct binTree stablo;
	stablo.right = NULL;
	stablo.left = NULL;
	int i = 0;
	srand(time(NULL));
	for (i = 0; i < 50; i++)
	{
		unos(&stablo, rand() % 100 + 1);
	}
	ispis(&stablo);

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
		printf("%d\n", p->Num);
		ispis(p->left);
		ispis(p->right);
	}
	return NULL;
}
Pos trazi(Pos p, int br)
{
	if (p = NULL)
		return NULL;
	else if (br < p->Num)
		return trazi(p->left, br);
	else if (br > p->Num)
		return trazi(p->right, br);
	else
		return p;
}
Pos traziMin(Pos p)
{
	if (p->left == NULL)
		return p;
	else 
		return traziMin(p->left);
}
Pos brisi(Pos p, int br)
{
	Pos temp = NULL;
	temp = (Pos)malloc(sizeof(struct binTree));
	if (p == NULL)
		printf("Nema ga!");
	else if (br < p->Num)
		p->left = brisi(p->left, br);
	else if (br > p->Num)
		p->right = brisi(p->right, br);
	else if (p->left != NULL && p->right != NULL)
	{
		temp = traziMin(p->right);
		p->Num = temp->Num;
		p->right = brisi(p->right, p->Num);
	}
	else
	{
		temp = p;
		if (p->left == NULL)
			p = p->right;
		else
			p = p->left;
		free(temp);
	}
	return p;
}
