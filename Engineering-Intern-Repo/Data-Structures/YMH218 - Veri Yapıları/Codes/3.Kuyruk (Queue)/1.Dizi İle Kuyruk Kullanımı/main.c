#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int *array=NULL;//array � bo� olarak tan�mlad�k
int order=0,orderHead=0,size=2;//s�raba��,s�ra ve boyutu tan�mlad�k
int deque(){//��karma i�lemi i�in deque fonk. tan�mlad�k
	if(order==orderHead)//e�er s�raba�� s�raya e�itse
	{
		printf("S�ra Bo�");//s�ra bo� yazs�n
		return -1 ;//-1 d�nderir
	}
	if(order-orderHead<=size/4){//s�ra-s�raba�� boyutun 4te 1inden k���kse
		int*arrayTemp=(int*)malloc(sizeof(int)*size/2);//dizitakas kutusu olu�tur
		int i=0;//for i�in i tan�mla
		for(i=0;i<order-orderHead;i++)//s�ra-s�raba��na kadar d�n�y� d�nder
		{
			 arrayTemp[i]=array[orderHead+i];//ilk dizimizi yeni dizimize atar�z her ad�mda
		}
		order-=orderHead;//s�raba��n� kopyalar�z
		orderHead=0;//s�raba��n�=0 e�itleriz
		free(array);//diziyi ram den sileriz
		size/=2;//boyutumuzu 2 ye b�leriz
		array=arrayTemp;//takasdizimizi dizimize atar�z
	}
	return array[orderHead++];//dizimizden ��karmam�z i�in s�raba��n� artt�r�rz
}
void clearArray(){//ortal��� toparlamas� i�in b�yle bir fonk. yazma gere�i duyduk
	if(orderHead==0)//s�raba�� 0 ise
	{
		return ;//bo� d�nder
	}
	int i;//for i�in i yi tan�mlad�k
	for(i=0;i<size;i++)//boyut kadar d�nderdik
	{
		array[i]=array[i+orderHead];//dizimizi kayd�rd�k
	}
	order-=orderHead;//s�ram�z� azalt�p s�raba��na e�itledik
	orderHead=0;//s�raba��m�z� 0 e�itledik
}
void enque(int x)//ekleme i�i i�in enque ve eklenecek de�er i�in x i tan�mlad�k
{
	if(array==NULL)//dizi bo�sa
	{
		array=(int*)malloc(sizeof(int)*2);//dizinin boyutunu 2 kat�na ��kar	
	}
	if(order>=size){//s�ra boyuttan b�y�k e�itse
		size*=2;//boyut 2ile �arp
		int *arrayTemp=(int*)malloc(sizeof(int)*size*2);//dizitakas kutusunu 2 kat b�y�kl���nde olu�tur
		int i=0;//for i�in i tan�mla
		for(i=0;i<size/2;i++)//boyutun yar�s� kadar d�ng�y� d�nd�r
		{
			arrayTemp[i]=array[i];//dizimizi dizitakasa atad�k her ad�mda
		}
		free(array);//dizi yi ramden sildik
		array=arrayTemp;//dizitakas� diziye kopyalad�k
	}
	array[order++]=x;//dizimizin s�ras�n� artt�r�p x e�itledik (ekleme i�lemi yapt�k)
}
int main(int argc, char *argv[]) {
	int i=0;int j=0;//d�ng� de�i�kenlerimiz tan�mlad�k
	for(i=0;i<20;i++)//d�ng� olu�turduk
	{
		enque(i*10);//ekledik
	}	
	printf("Durum : \nBoyut : %d \nS�ra : %d \nS�raba�� : %d\n",size,order,orderHead);//yazd�rd�k
	for(j=0;j<13;j++)//d�ng� olu�turduk
	{
		printf("%d \n",deque());//��kard�k
	}
	//clearArray();
	printf("Durum : \nBoyut : %d \nS�ra : %d \nS�raba�� : %d\n",size,order,orderHead);//yazd�rd�k
	for(i=0;i<20;i++)//d�ng� olu�turduk
	{
		enque(i*10);//ekledik
	}
	printf("Durum : \nBoyut : %d \nS�ra : %d \nS�raba�� : %d\n",size,order,orderHead);//yazd�rd�k
	for(j=0;j<30;j++)//d�ng� olu�turduk
	{
		printf("%d \n",deque());//��akrd�k
	}
	printf("Durum : \nBoyut : %d \nS�ra : %d \nS�raba�� : %d\n",size,order,orderHead);//yazd�rd�k
	return 0;
	getch();
}
