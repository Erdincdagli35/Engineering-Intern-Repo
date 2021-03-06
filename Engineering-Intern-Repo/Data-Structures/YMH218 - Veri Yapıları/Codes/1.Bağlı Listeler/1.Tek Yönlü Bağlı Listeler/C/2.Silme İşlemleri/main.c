#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
struct n{ //n ad�nda bir yap� olu�turduk
	int x;struct n*next;
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
	printf("\n");//bir sat�r a�a��ya indik	
}
node* arraySequentialAdding(node *r,int x)//her zamanki gibi r pointer� ve x de�i�neinin paramtre olarak tam�nlad�k
{
	if(r==NULL)//e�er listemiz bo�sa
	 {
	 	r=(node*)malloc(sizeof(node));//bir data olu�turacak
		r->next=NULL;//datam�z�n kuyru�unu Null yapaca��z devaml�l��� sa�lamak i�in
		r->x=x;	//ve ilk datam�z�n de�erini girece�iz
		return r;//ve bu datay� d�nderece�iz
	 }
	 if(r->x>x)//ilk elemandan k���k durumu kontol ediyoruz(buna ayn� zamamda ba�a ekleme diyebiliriz)
	 	{//root de�i�iyor(root datas�n�n bir i�inde bir de�eri oluyor)
	 		node*temp=(node*)malloc(sizeof(node));//her zaman ki gibi kutu olu�turuyoruz
			temp->x=x;//olu�turdu�umuz kutuya de�erimizi at�yoruz
			temp->next=r;//temp datas�n�n kuyru�u r pointer�na e�it olam�l�d�r
			//r=temp;
			return temp;//son olarak temp datas�n� d�nderiyoruz
		}	
	 node*iter =r;//r pointer�m�z� iter pointer�na e�itledik
	 while(iter->next!=NULL&&iter->next->x<x){//e�er ilk de�er ikinci de�erden k���kse(bu durum do�rudur) ve iter pointer�n�n kuyru�u bo� de�ilse
	 	iter=iter->next;//iter pointer�n�n kuyru�u itere e�itolacakt�r.(liste i�inde dola�mal�y�z) i�lem yapadan devam etmeliyiz yani
	 }
	 node*temp=(node*)malloc(sizeof (node));//e�er while d�ng�n� kar��lamazsa bir kutu olu�turacakt�r.
	 temp->next=iter->next;//ortaya eklemede yapt���m�z ayn� mant�kta ilk olarak iterin kuyru�unu temp in kuyur�una ba�lar�z
	 iter->next=temp;//temp i de iterin kuyru�una ba�lar�z(bu kod her zaman bi �nceki kodtan sonra yaz�lmal�d�r.)yoksa liste ba�lant�s� kopar
	 temp->x=x;//temp datam�za istedi�imz de�eri yaz�r�yoruz
	 return r;//son olarak r yi d�nderiyoruz
	 
	 }
	node * removeArrayElement(node* r,int x)//her zaman oldu�u gibi r pointer� ve x de�erini parametre olarak ba�lad�k
	{
		node * temp;//temp pointer�n� d���mden ekledik
		node * iter=r;//iter pointer�n� r pointer�na e�itledik
		if(r->x==x)//r nin data de�eri x de�erine e�itese orda duracak ve
		{
			temp=r;//r datas�n�temp datas�na atayacak (ba�lant�y� uygun bir �ekilde koparmamak i�in)
			r=r->next;//ard�ndan r nin kuyru�unu r ye atayaca��z 
			free(temp);//free fonk kullanarak ram deki temp datas�n� temizleyece�iz
			return r;//son olarak r yi d�nderece�iz
		}
		while(iter->next!=NULL && iter->next->x!=x)//iter pointer�m�z�n kuyru�u bo� de�ilse ve iterin kuyru�unun de�eri bo� de�ilse d�ng�m�z d�necek
		{
			iter=iter->next;//her zaman yapt���m�z gibi devaml�l�k i�in bu kodu kullanmal�y�z
						
		}
		if(iter->next==NULL)//e�er iterin kuyru�u bo�sa
		{	
			printf("\nSayi Bulunamadi !!\n");
			return r;//say� bulunamad�
			
		}
		temp=iter->next;//hi�bir sorguyu kar��lam�yorsa iterin kuyru�u tempe e�itledik
		iter->next=temp->next;//iter->next=iter->next->next �ekilde de yazabiliriz temp=iter->next e�it oldu�u i�in �yle yaz�k
		free(temp);//ramden temp datas�n� temizledik
		return r;//r datas�n� d�nderdik
	}
int main(int argc, char *argv[]) {
	node * root;//k�k datas�n� d���mden pointer olarak at�yoruz
	root=NULL;//root datam�z� bo� tan�ml�yoruz
	root=arraySequentialAdding(root,40);//k�k datal� 400 say�s�n� ekliyoruz
	root=arraySequentialAdding(root,4);//k�k datal� 40 say�s�n� ekliyoruz
	root=arraySequentialAdding(root,4000);//k�k datal� 4 say�s�n� ekliyoruz
	root=arraySequentialAdding(root,450);//k�k datal� 450 say�s�n� ekliyoruz
	root=arraySequentialAdding(root,50000 );//k�k datal� 500 say�s�n� ekliyoruz
	printArray(root);//k�k bazl� yaz�rma methodunu kullan�yoruz
	root=removeArrayElement(root,50);//k�k datal� 50 de�eri olan datay� silmeye �al��t�k
	printArray(root);//k�k bazl� yaz�rma methodunu kullan�yoruz
	root=removeArrayElement(root,999);//k�k datal� 999 de�eri olan datay� silmeye �al��t�k
	printArray(root);//k�k bazl� yaz�rma methodunu kullan�yoruz
	root=removeArrayElement(root,4);//k�k datal� 4 de�eri olan datay� sildik
	printArray(root);//k�k bazl� yaz�rma methodunu kullan�yoruz
	root=removeArrayElement(root,450);//k�k datal� 450 de�eri olan datay� sildik
	printArray(root);//k�k bazl� yaz�rma methodunu kullan�yoruz
	return 0;
	getch();
}
