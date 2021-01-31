#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
struct n{ //n ad�nda bir yap� olu�turduk
	int x;struct n*next;struct n*prev;//x in �ncesi i�in prev tan�mlad�k
	//Herhangibir x de�eri ve x de�erinin sonras� i�in next i tan�mlad�k 
	
};
typedef struct n node;//
void printArray(node * r)//r olarak tan�mlanm�� pointerla printArray ad�nda method olu�turduk
{
	while(r!=NULL)//e�er r pointer � bo� de�ilse yazd�rma i�lemi yap
	{
		printf("%d \n",r->x);//r pointerin datas�n� yazd�r.
		r=r->next;//bir sonraki dataya ge�
	}
	printf("\n");	
}
node* arraySequentialAdding(node *r,int x)//her zamanki gibi r pointer� ve x de�i�neinin paramtre olarak tam�nlad�k
{
	if(r==NULL)//e�er listemiz bo�sa
	 {
	 	r=(node*)malloc(sizeof(node));//bir data olu�turacak
		r->next=NULL;//datam�z�n kuyru�unu Null yapaca��z devaml�l��� sa�lamak i�in
		r->prev=NULL;
		r->x=x;	//ve ilk datam�z�n de�erini girece�iz
		return r;//ve bu datay� d�nderece�iz
	 }
	 if(r->x>x)//ilk elemandan k���k durumu kontol ediyoruz(buna ayn� zamamda ba�a ekleme diyebiliriz)
	 	{//root de�i�iyor(root datas�n�n bir i�inde bir de�eri oluyor)
	 		node*temp=(node*)malloc(sizeof(node));//her zaman ki gibi kutu olu�turuyoruz
			temp->x=x;//olu�turdu�umuz kutuya de�erimizi at�yoruz
			temp->next=r;//temp datas�n�n kuyru�u r pointer�na e�it olam�l�d�r
			r->prev=temp;
			return temp;//son olarak temp datas�n� d�nderiyoruz
		}	
	 node*iter =r;//r pointer�m�z� iter pointer�na e�itledik
	 while(iter->next!=NULL&&iter->next->x<x){//e�er ilk de�er ikinci de�erden k���kse(bu durum do�rudur) ve iter pointer�n�n kuyru�u bo� de�ilse
	 	iter=iter->next;//iter pointer�n�n kuyru�u itere e�itolacakt�r.(liste i�inde dola�mal�y�z) i�lem yapadan devam etmeliyiz yani
	 }
	 node*temp=(node*)malloc(sizeof (node));//e�er while d�ng�n� kar��lamazsa bir kutu olu�turacakt�r.
	 temp->next=iter->next;//ortaya eklemede yapt���m�z ayn� mant�kta ilk olarak iterin kuyru�unu temp in kuyur�una ba�lar�z
	 iter->next=temp;//temp i de iterin kuyru�una ba�lar�z(bu kod her zaman bi �nceki kodtan sonra yaz�lmal�d�r.)yoksa liste ba�lant�s� kopar
	 temp->prev=iter;//iter i temp datas�n�n �ncesine e�itledik
	 if(temp->next!=NULL)//e�er tempin kuyru�u bo� de�ilse 
	 	temp->next->prev=temp;//temp i temp datas�n�n kuyru�unun �ncesine ata
	 temp->x=x;//temp datam�za istedi�imz de�eri yaz�r�yoruz
	 return r;//son olarak r yi d�nderiyoruz
	 
	 }
	 node* arrayDelete(node *r ,int x)//silme fonk. r pointer� ve int tan�mlanan x ten olu�mu�tur
	 {
	 	node * temp;//d���mde temp pointer�n� tan�mlad�k
	 	node*iter=r;//iter pointer�n�n r ye e�itledik
	 	
	 	if(r->x==x)//r pointer� de�eri x de�erine e�itese
	 	{
	 		temp=r;//r yi tempe atad�k
	 		r=r->next;//r nin kuyru�unu r ye atad�k 
	 		free(temp);//ram den temp i sildik
	 		return r;//r yi d�nderdik
		}
		while(iter->next!=NULL && iter->next->x!=x){//daha �nce dedi�imiz gibi ayn� �ekilde bu sorgu sa�land��� s�rec
		 	iter=iter->next;//listede d�necek
		}		 	
		if(iter->next==NULL)//iterin kuyru�u bo�sa
		{
			printf("\nSay� Bulunamad�\n");
			return r;//r yi d�nder
		}
		temp=iter->next;//iterin kuyru�u tempe atad�k
		iter->next=iter->next->next;//iterin kuru�unun kuyru�unu iterin kuyuru�una atad�k
		free(temp);//ram  den tempi sildik
		if(iter->next!=NULL)//iterin kuyru�u bo� de�ilse
			iter->next->prev=iter;//iteri iterin kuyru�unun �ncesine ata
		return r;//r yi d�nder
	 }
int main(int argc, char *argv[]) {
	node * root;//k�k datas�n� d���mden pointer olarak at�yoruz
	root=NULL;//root datam�z� bo� tan�ml�yoruz
	root=arraySequentialAdding(root,400);//k�k datal� 400 say�s�n� ekliyoruz
	root=arraySequentialAdding(root,40);//k�k datal� 40 say�s�n� ekliyoruz
	root=arraySequentialAdding(root,4);//k�k datal� 4 say�s�n� ekliyoruz
	root=arraySequentialAdding(root,450);//k�k datal� 450 say�s�n� ekliyoruz
	root=arraySequentialAdding(root,50 );//k�k datal� 500 say�s�n� ekliyoruz
	printArray(root);//k�k bazl� yaz�rma methodunu kullan�yoruz
	root=arrayDelete(root,50);//k�k datal� 50 say�s�n� bulup silmeye �al���yoruz
	printArray(root);//k�k bazl� yaz�rma methodunu kullan�yoruz
	root=arrayDelete(root,999);//k�k datal� 999 say�s�n� bulup silmeye �al���yoruz
	printArray(root);//k�k bazl� yaz�rma methodunu kullan�yoruz
	root=arrayDelete(root,4);//k�k datal� 4 say�s�n� bulup silmeye �al���yoruz
	printArray(root);//k�k bazl� yaz�rma methodunu kullan�yoruz
	root=arrayDelete(root,450);//k�k datal� 450 say�s�n� bulup silmeye �al���yoruz
	printArray(root);//k�k bazl� yaz�rma methodunu kullan�yoruz
	
	return 0;
	getch();
}
