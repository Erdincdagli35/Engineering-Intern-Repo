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
}
void addingArrayRight(node* r,int x)//son ekleme yapabilmesi i�in pointer ve x de�eri tan�mlad�k paramaetre olarak
{
	while(r->next!=NULL){//e�er r pointer�n�n kuyru�u bo� de�ilse 
		r=r->next;//di�er datadan devam et
	}
	r->next=(node*)malloc(sizeof(node));//bo�sa bir kutu olu�tur.(r pointer�n�n kuyru�unda)
	r->next->x=x;//r pointe�n�n sonuna x i ekle
	r->next->next=NULL;//x sonras�n�n sonras� Null ata ki devaml�l�k sa�lanabilsin
	
}
void addingArrayMiddle(node*iter,int x,int index)//Ortaya ekleme yapabilmek i�in iter pointer�,eklenecek x de�eri,ve silinecek yer i�in index de�eri tan�mlad�k
{
	node*root;//k�k d���m� poiter olarak g�sterdik
	int i=0;//i de�i�kenini tan�mlad�k
	for(i=0;i<=index-2;i++)//for d�ng�m�y�z� a�t�k 
	{
		iter=iter->next;//durmam�z gereken yere kadar datalar�n aras�nda gezinmemizi sa�layacak
	}
	node*temp=(node*)malloc(sizeof(node));//daha kolay i�lem yapabilmek i�in temp ad�nda data olu�turduk
	temp->next=iter->next;//(Her zaman �ncelikli olarak bunu yapmal�y�z)tempin kuyru�una iterin kuyru�unu ba�lad�k
	iter->next=temp;//temp i de iterin kuyru�una ba�layarak kam��lama i�lemi yap�p araya kutuyu eklemi� olduk
	temp->x=x;//son olarakta temp datam�z�n i�ine girilmesi istenilen dee�eri yazd�rd�k
}

int main(int argc, char *argv[]) {
	node * root;//k�k d���m� olu�tur.
	root=NULL;
	root=(node*)malloc(sizeof(node));//bir data(kutu) olu�tur.
	root->x=50;//k�k datas�na 50 de�erini ata (bu mutlaka yap�lamal�d�r.Program �al��maz aksi durumda) 
	root->next=NULL;//k�k datas�n�n kuyru�una Null ata ki devaml�l��� sa�layabilsin
	addingArrayRight(root,33);//sona ekleme yapt�k
	addingArrayRight(root,44);//sona ekleme yapt�k
	addingArrayRight(root,55);//sona ekleme yapt�k
	addingArrayMiddle(root,11,3);//11 de�erini 3 datadan sonra ekledik.
	addingArrayMiddle(root,66,2);//66 de�erini 2 datadan sonra ekledik
	printArray(root);//datalar�m�z� yazd�rd�k.
	return 0;
	getchar();
}
