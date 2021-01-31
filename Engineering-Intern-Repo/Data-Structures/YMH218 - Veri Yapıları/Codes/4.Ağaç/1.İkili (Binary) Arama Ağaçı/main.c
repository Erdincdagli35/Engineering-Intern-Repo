#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
/* A:�kiliA�a�
	�zyineli(Recursive) Tan�m�
	1.Bo� Olabilir
	2.�ki �ocu�unda da ikili a�a� olan (subtree)d���m
	3.1 ve 2 li yap�lar�n sonlu uygulanmas�yla elde edilen yap�d�r 
   B:�kili Arama A�ac�
    -Belli bir say� s�rlamas�n�n a�aca yerle�tirilmii� halidir	
 */
struct node{//d���m�m�z� sturct yap�s�nda tan�mlad�k
	struct node*left;//left de�ikeni sol
	struct node*right;//right de�i�keni sa� i�in
	int x;//x ifadeside gelen say� i�in
};
struct node*adding(struct node*tree,int x)//ekleme modl�n� olu�turmak i�in x de�erini istedik parametre olarak
{
	if(tree==NULL)//e�er a�ac�m�z bo� ise
	{
		struct node*root=(struct node*)malloc(sizeof(struct node));//root ad�nda bir kutu olu�turaca��z
		root->left=NULL;//rootun solunu null
		root->right=NULL;//sa��n null yyap�caz
		root->x=x;//rootun datas�na x yazaca��z
		return root;//root u d�nderece�iz
	}
	if(tree->x<x)//e�er a�ac�n datas� girilen x de�erinden k���kse
	{		tree->right=adding(tree->right,x);//(recursive fonk kullan�larak) a�ac�n sa��na ekleyece�iz
			return tree;// ve a�ac� d�nderece�iz
	}
	tree->left=adding(tree->left,x);//de�ilse a�ac�n soluna ekleyip
	return tree;//ayn� �ekilde a�ac� d�nderece�iz
	
}
void infix(struct node*tree)//infix gezinme metodu (Left-Tree-Right) mant��� k�ullan�l�r
{	
	if(tree==NULL)//e�er a�a� bo� ise
	{
		return;//bo� de�er d�nder
	}//de�ilse
	infix(tree->left);//ilk (LTR) mant���ndan lefti yazd�r
	printf("%d\n",tree->x);//sonra k�k �
	infix(tree->right);//sonrada right � d�nder
}
void postfix(struct node*tree)//postfix gezinme metodu(Left-Right-Tree) mant��� kullan�l�r
{
	if(tree==NULL){//e�er a�a� bo�sa 
		return;//bo� de�er d�nder
	}//de�ilse(recursive fonk. ile)
	postfix(tree->left);//ilk sol u yazd�r
	postfix(tree->right);//sonra sa�� yazd�r
	printf("%d \n",tree->x);//k�k � yazd�r
}
void prefix(struct node*tree)//prefix gezinme methodu ise (Tree-Left-Right) mant��� ile �al���r
{
	if(tree==NULL)//e�er a�a� bo�sa  
	{
		return;//bo� de�er d�nder
	}
	printf("%d \n",tree->x);//ilk k�k� yaz�dr
	prefix(tree->left);//sonra solu
	prefix(tree->right);//sonra sa�� yaz�dr
}
int find(struct node*tree,int a)//Bulma fonk i�in a de�ikeni tan�mlam�z yeterli olacakt�r parametre olarak
{
	if(tree==NULL)//a�a� bo�sa 
	{
		return -1;//-1 de�erini d�nder
	}
	if(tree->x==a)//a�ac�n datas� a de�erine e�itse
	{
		return 1;//1 de�erini d�nder
	}
	if(find(tree->right,a)==1)//e�er a�ac�n sa��nda a de�erine 1 e�itse 
		return 1;//1 d�nder
	if(find(tree->left,a)==1)//e�er a�ac�n solunda a de�erine 1 e�itse
		return 1;//1 d�nder
	return -1;//akis halde yine -1 d�nder
	
}


struct node*del(struct node*tree,int x){//silme metodu i�in x de�erini parametre olarak tan�mlad�k
	if(tree==NULL)//a�a� bo�sa 
	{
		return NULL;//bo� de�er d�nder
	}
	if(tree->x==x){//a�ac�n datas� x e�itse
		if(tree->left==NULL&&tree->right==NULL)//e�er a�ac�n solu bo�sa ve a�ac�n sa��da bo�sa 
			return NULL;//bo� de�er d�nder
		if(tree->right!=NULL){//e�er a�ac�n sa�� bo� de�ilse
			tree->x=min(tree->right);//sa�daki a�ac�n�n minimum de�erini a�ac�n x datas�na yaz
			tree->right=del(tree->right,min(tree->right));//a�ac�n en k���k sa� de�erini a�ac�n sa��na ata
			return tree;//a�ac� d�nder
		}//de�ilse
		tree->x=max(tree->left);//a�ac�n solunun en b�y�k de�eri a�ac�n de�erine ata 
		tree->left=del(tree->left,max(tree->left));//soldaki a�ac�n maximum de�erini soldaki a�aca yaz
		return tree;//a�ac� d�nder
	}
	if(tree->x<x)//a�ac�n datas� x girilen x de�erinde k���kse
	{
		tree->right=del(tree->right,x);//sa� a�actaki de�eri sil a�ac�n sa�� siil
		return tree;//a�ac� d�nder
	}//de�ilse
	tree->left=del(tree->left,x);//sol a�actaki de�eri sol a�acan� solu sil
	return tree;//a�ac� d�nder
}
int max(struct node*tree)//a�actaki max de�eri bulmak i�in 
{
	while(tree->right!=NULL)//a�ac�n sa�saki de�eri bo� de�ilse
	{//sa�da dola�mam�z�n mant��� en b�y�k eleman hep sa�da olur
		tree=tree->right;//a�ac�n sa��nda dola�
	}
	return tree->x;//a�ac�n datas�n� d�nder
}
int min(struct node*tree)//a�a�taki min de�erini bulmak i�in
{
	while(tree->left!=NULL)//a�ac�n solu bo� de�ilse
	{//solda dola�mam�z�n sebebi a�ac�n solu en k���k de�er olur
		tree=tree->left;//solu dola�
	}
	return tree->x;//a�ac�n datas�n� yazd�r
}
int leaves(struct node * tree)
{
	int s=0,sLeft=0,sRight=0;
	infix(tree);
	while(tree->left!=NULL)
	{
		//tree=tree->left;
		if(tree->left==NULL && tree->right==NULL)
		{
			sLeft++;
		}
		
	}
	while(tree->right!=NULL)
	{
		//tree=tree->right;
		if(tree->left==NULL && tree->right==NULL)
		{
			sRight++;
			
		}
	}
	s=sLeft+sRight;
	return sLeft;
}
int main(int argc, char *argv[]) {
	struct node*tree=NULL;
	/*tree=adding(tree,56);
	tree=adding(tree,200);
	tree=adding(tree,26);
	tree=adding(tree,190);
	tree=adding(tree,213);
	tree=adding(tree,18);
	tree=adding(tree,28);
	tree=adding(tree,12);
	tree=adding(tree,24);
	tree=adding(tree,27);
	infix(tree);printf("------------------------\n");
	postfix(tree);printf("------------------------\n");
	prefix(tree);
	//printf("\nArama Sonucu : %d ",find(tree,24));
	printf("\nEn buyuk eleman : %d",max(tree));
	printf("\nEn kucuk eleman : %d\n",min(tree));
	tree=del(tree,56);
	infix(tree);*/
	tree=adding(tree,2);
	tree=adding(tree,3);
	tree=adding(tree,4);
	tree=adding(tree,5);
	tree=adding(tree,7);
	tree=adding(tree,8);
	/*tree=adding(tree,1);
	tree=adding(tree,15);
	tree=adding(tree,13);
	tree=adding(tree,14);*/
	infix(tree);printf("En B�y�k : %d\nEn K���k : %d\nYaprak Say�s� : %d",max(tree),min(tree),leaves(tree));
	//leaves(tree);
	return 0;
	getch();
}
