#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int *array=NULL;//array ý boþ olarak tanýmladýk
int order=0,orderHead=0,size=2;//sýrabaþý,sýra ve boyutu tanýmladýk
int deque(){//çýkarma iþlemi için deque fonk. tanýmladýk
	if(order==orderHead)//eðer sýrabaþý sýraya eþitse
	{
		printf("Sýra Boþ");//sýra boþ yazsýn
		return -1 ;//-1 dönderir
	}
	if(order-orderHead<=size/4){//sýra-sýrabaþý boyutun 4te 1inden küçükse
		int*arrayTemp=(int*)malloc(sizeof(int)*size/2);//dizitakas kutusu oluþtur
		int i=0;//for için i tanýmla
		for(i=0;i<order-orderHead;i++)//sýra-sýrabaþýna kadar dönüyü dönder
		{
			 arrayTemp[i]=array[orderHead+i];//ilk dizimizi yeni dizimize atarýz her adýmda
		}
		order-=orderHead;//sýrabaþýný kopyalarýz
		orderHead=0;//sýrabaþýný=0 eþitleriz
		free(array);//diziyi ram den sileriz
		size/=2;//boyutumuzu 2 ye böleriz
		array=arrayTemp;//takasdizimizi dizimize atarýz
	}
	return array[orderHead++];//dizimizden çýkarmamýz için sýrabaþýný arttýrýrz
}
void clearArray(){//ortalýðý toparlamasý için böyle bir fonk. yazma gereði duyduk
	if(orderHead==0)//sýrabaþý 0 ise
	{
		return ;//boþ dönder
	}
	int i;//for için i yi tanýmladýk
	for(i=0;i<size;i++)//boyut kadar dönderdik
	{
		array[i]=array[i+orderHead];//dizimizi kaydýrdýk
	}
	order-=orderHead;//sýramýzý azaltýp sýrabaþýna eþitledik
	orderHead=0;//sýrabaþýmýzý 0 eþitledik
}
void enque(int x)//ekleme iþi için enque ve eklenecek deðer için x i tanýmladýk
{
	if(array==NULL)//dizi boþsa
	{
		array=(int*)malloc(sizeof(int)*2);//dizinin boyutunu 2 katýna çýkar	
	}
	if(order>=size){//sýra boyuttan büyük eþitse
		size*=2;//boyut 2ile çarp
		int *arrayTemp=(int*)malloc(sizeof(int)*size*2);//dizitakas kutusunu 2 kat büyüklüðünde oluþtur
		int i=0;//for için i tanýmla
		for(i=0;i<size/2;i++)//boyutun yarýsý kadar döngüyü döndür
		{
			arrayTemp[i]=array[i];//dizimizi dizitakasa atadýk her adýmda
		}
		free(array);//dizi yi ramden sildik
		array=arrayTemp;//dizitakasý diziye kopyaladýk
	}
	array[order++]=x;//dizimizin sýrasýný arttýrýp x eþitledik (ekleme iþlemi yaptýk)
}
int main(int argc, char *argv[]) {
	int i=0;int j=0;//döngü deðiþkenlerimiz tanýmladýk
	for(i=0;i<20;i++)//döngü oluþturduk
	{
		enque(i*10);//ekledik
	}	
	printf("Durum : \nBoyut : %d \nSýra : %d \nSýrabaþý : %d\n",size,order,orderHead);//yazdýrdýk
	for(j=0;j<13;j++)//döngü oluþturduk
	{
		printf("%d \n",deque());//çýkardýk
	}
	//clearArray();
	printf("Durum : \nBoyut : %d \nSýra : %d \nSýrabaþý : %d\n",size,order,orderHead);//yazdýrdýk
	for(i=0;i<20;i++)//döngü oluþturduk
	{
		enque(i*10);//ekledik
	}
	printf("Durum : \nBoyut : %d \nSýra : %d \nSýrabaþý : %d\n",size,order,orderHead);//yazdýrdýk
	for(j=0;j<30;j++)//döngü oluþturduk
	{
		printf("%d \n",deque());//çýakrdýk
	}
	printf("Durum : \nBoyut : %d \nSýra : %d \nSýrabaþý : %d\n",size,order,orderHead);//yazdýrdýk
	return 0;
	getch();
}
