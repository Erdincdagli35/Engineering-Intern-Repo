#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
struct node{//struct olarak bir d���m olu�turduk
	struct node*next;//d���m�n kuyru�u i�in next i ekledik
	int x;//x de�i�enin tan�mlad�k
};
void listPrint(struct node*root)//listemizi yazd�rmak i�in struct node * root pointer�n� struct d���m�nden ald�k
{
	struct node*iter=root;//d���m�den iter pointer�n� itere e�itledik
	int i =0;//for i�in i=0 tan�mlad�k
	while(iter!=NULL)//iter bo� de�ilse
	{
		
		printf("%d \n",iter->x);//iter->x yani de�erimizi yazd�r ve bir sat�r a�a��ya in 
		iter=iter->next;//listede dola�
	} 
}
struct node* push(struct node*root,int x)//eklemek i�in x de�erine ihtiyac�m�z var bu �ekilde tan�mlad�k fonk.
{
	if(root==NULL)//k�k pointer� bo�sa
	{
		root=(struct node*)malloc(sizeof(struct node));//bir kutu olu�tur
		root->x=x;//kutuya istedi�imiz(x) de�erini ekle
		root->next=NULL;//k�k pointer�n kuyru�unu bo� yap(ba�l� liste mant���ndan geliyor)
		return root;//son olarak root u d�nder
	}
	struct node *iter =root;//iter pointer�n� roota e�itle 
	while(iter->next!=NULL)//e�er iterin kuyru�u bo� de�ilse 
	{
		iter=iter->next;//her ba�l� listede oldu�u gibi bu durumdada dola�acak
	}
	iter->next=(struct node*)malloc(sizeof(struct node));//de�ilse iterin kuyru�una bir kutu olu�turacak
	iter->x=x;//kutunun i�ine istenilen de�er girilicek
	iter->next->x=x;//ayn� �ekilde kuyru�una da istenilen de�er girilicek
	iter->next->next=NULL;//kuyru�unun kuyru�u ise bo� olacak (ba�l� liste mant���ndan)
	return root;//son olarak root u d�nder
	
}
struct node* pop(struct node*root){//pop (listeden ��karma i�lemi i�in struct �eklide tan�mlan�r)
	if(root->next==NULL)//root un kuyru�u bo�sa
	{
		root=NULL;//root ta bo� olmal�d�r
		return root;//root u d�ndermelidir
	}
	if(root==NULL)//e�er root bo�sa
	{
		printf("Stack Bo�");//ekrana stock bo� bast�r�l�r
		return root;//root d�nderilir
	}
	else{//de�ilse
		struct node*iter=root;//iter pointer� root a e�itlenir 
		while(iter->next->next!=NULL)//e�er iterin kuyru�unun kuyru�u bo� de�ilse
		{
			iter=iter->next;//listede dola��r
		}	
		iter->next=NULL;//iter�n kuyru�unu bo� yapar (b.liste mant���)
		return root;//root d�nderilir
	}
	
}

int main(int argc, char *argv[]) {
	struct node*root=NULL;//bo� bir root pointer� tan�mlan�r
	int i;//for i�in i tan�mlan�r
	for(i=0;i<10;i++)//1 den 10 kadar eklenemesi i.in for a��l�r
	{
		root=push(root,i*5);//yazd���m�z push methodunu root pointer� yard�m�yla kullanarak 5 in katlar�n� ekleriz
	}
	listPrint(root);//root bazl� yazd�rma i�lemi yapar�z
	printf("Pushlad�k\n------------------------------------\n");//ekrana yazd�r�r�z
	for(i=0;i<5;i++)//1den 5 e kadar pop metoduyla ��karmaya �al���r�z
	{
		root=pop(root);//son eklenenden ilk eklenene do�ru ��akr�z
	}
	listPrint(root);//root bazl� ekrana bast�r�z
	printf("Poplad�k\n------------------------------------\n");//ekrana yazd�r�r�z
	return 0;
	getch();
}
