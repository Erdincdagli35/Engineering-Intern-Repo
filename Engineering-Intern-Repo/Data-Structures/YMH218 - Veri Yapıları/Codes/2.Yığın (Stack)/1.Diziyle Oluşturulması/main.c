#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int *array;//pointer olarak dizi de�i�keni tan�mlad�k
int size=2;//boyutunu 2 olarak belirledik
int top=0;//tepe noktas�n� 0 olarak belirledik

//Pop un mant��� ilk giren son ��kar 
int pop()//pop un mant��� bir dizideki en son giren eleman� diziden ��kar�r
{
	if(array==NULL){//dizimiz bo� ise
	
		printf("Dizi Bo�");//dizi bo� ifaddesini ekrana bast�r�r.
		return -1;//-1 de�erini d�nderir
	}
	if(top<=size/4)//e�er boyutumuz 4te 1i tepe noktam�zdan b�y�kse 
	{
		int *arrayTemp=(int*)malloc (sizeof(int )*size/2);//takasdizimiz(arrayTemp) i yar� boyutunda bir kutu olu�turacak 
		int i=0;//for d�ng�s� i�in d��ar�da i de�i�kenini tan�mlad�k
		for(i=0;i<size;i++)//boyutumuza kadar d�necek ve 1 er 1 er artacak
		{
			arrayTemp[i]=array[i];//her bir for ad�mda dizimizin i.ci de�erini dizitakastaki i.nc de�erine atayacak		
		}
		free(array);//dizi de�i�keniye i�imiz kalmad��� i�in ram den sileriz
		array=arrayTemp;//takasdiziyi diziye e�itleriz
		size/=2;//boyutumuzu 2 ye b�leriz	
	}
	return array[--top];//pop i�lemini sa�labilmemiz i�in dizimizin tepe de�erini 1 azalt�r�z(mant�k olarak ba�tada dedi�imz gibi diziden(dizinin ba��ndan) ��kar�r�z)
}
void push (int x)//push metodu mant�k olarak parametre olarak tam�nlad���m�z x de�erini dizinin son eleman� olarak ekler
{
	if(array==NULL)//dizimiz bo�sa
	{
		int *array=(int*)malloc (sizeof(int )*size/2);//dizimiz bo�sa boyutu yar�ya indirilmi� bir kutu olu�turulur
	}
	if(top>=size)//e�er boyut tepe noktam�zdan b�y�k olursa (dizimizin boyutu b�y�m�� ve onu ba�ka bir diziye atmam�z gerekir)
	{
		int *arrayTemp=(int*)malloc (sizeof(int )*size*2);//dizitakas ad�nda ,dizi ad� verdi�imiz dizimizin 2 kat� olacak bir kutu olu�turuyoruz
		int i=0;//for i�in i de�i�keni tan�mlad�k
		for(i=0;i<size;i++)//i=0 da�layarak 1 er 1 er artarak ve boyut say�s�nda son bulacak �ekilde tan�mlan�r
		{
			arrayTemp[i]=array[i];//yeni ve daha b�y�k olan dizimiz dizi takasa her ad�mda ilk dizimizdeki verileri atar�z		
		}
		free(array);//art�k i�imize yaramayacak dizi de�i�kenimizi ram den sileriz
		array=arrayTemp;//dizitakas� diziye atar�z
		size*=2;//boyutu 2 ile artt�r�z
	}
	array[top++]=x;//push i�lemini sa�lamas� i�in dizimize girilen x de�erini ekleriz(dizimizin sonuna)
}
void arrayPrint()//her zaman olmas� gereken yazd�rma fonk.
{
	
	int i=0;
	printf("Boyut : %d\n",size);//boyutumuzun de�i�imini g�rmek i�in yazd�rd�k ve for d�ng�s� i�in i tan�mlad�k
	for(i=0;i<top;i++)//i=0 da�layarak 1 er 1 er artarak ve boyut say�s�nda son bulacak �ekilde tan�mlan�r
	{
		printf("%d \n",array[i]);//dizimiz de�erini her seferinde bir sat�r atlayarak yazd�rd�k
	}
	printf("\n");//bir sat�r atlad�k
}
int main(int argc, char *argv[]) {
	array=(int*)malloc(sizeof(int)*2);//dizi de�i�kenimizi bir kutu olu�turarak �a��rd�k
	push(10);//10 ekledik
	push(20);//20 ekledik
	push(30);//30 ekledik
	push(40);//40 ekledik
	push(50);//50 ekledik
	arrayPrint();//yazd�rd�k
	pop();//Pop i�lemi yaparak ��kartt�k
	pop();//Pop i�lemi yaparak ��kartt�k
	pop();//Pop i�lemi yaparak ��kartt�k
	pop();//Pop i�lemi yaparak ��kartt�k
	pop();//Pop i�lemi yaparak ��kartt�k
	arrayPrint();//yazd�rd�k
	push(10);//10 ekledik
	push(20);//20 ekledik
	push(30);//30 ekledik
	push(40);//40 ekledik
	push(50);//50 ekledik
	push(60);//60 ekledik
	push(70);//70 ekledik
	push(80);//80 ekledik
	push(90);//90 ekledik
	push(100);//100 ekledik
	arrayPrint();//yazd�rd�k
	return 0;
	getch();
}
