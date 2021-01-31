#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int *array;//pointer olarak dizi deðiþkeni tanýmladýk
int size=2;//boyutunu 2 olarak belirledik
int top=0;//tepe noktasýný 0 olarak belirledik

//Pop un mantýðý ilk giren son çýkar 
int pop()//pop un mantýðý bir dizideki en son giren elemaný diziden çýkarýr
{
	if(array==NULL){//dizimiz boþ ise
	
		printf("Dizi Boþ");//dizi boþ ifaddesini ekrana bastýrýr.
		return -1;//-1 deðerini dönderir
	}
	if(top<=size/4)//eðer boyutumuz 4te 1i tepe noktamýzdan büyükse 
	{
		int *arrayTemp=(int*)malloc (sizeof(int )*size/2);//takasdizimiz(arrayTemp) i yarý boyutunda bir kutu oluþturacak 
		int i=0;//for döngüsü için dýþarýda i deðiþkenini tanýmladýk
		for(i=0;i<size;i++)//boyutumuza kadar dönecek ve 1 er 1 er artacak
		{
			arrayTemp[i]=array[i];//her bir for adýmda dizimizin i.ci deðerini dizitakastaki i.nc deðerine atayacak		
		}
		free(array);//dizi deðiþkeniye iþimiz kalmadýðý için ram den sileriz
		array=arrayTemp;//takasdiziyi diziye eþitleriz
		size/=2;//boyutumuzu 2 ye böleriz	
	}
	return array[--top];//pop iþlemini saðlabilmemiz için dizimizin tepe deðerini 1 azaltýrýz(mantýk olarak baþtada dediðimz gibi diziden(dizinin baþýndan) çýkarýrýz)
}
void push (int x)//push metodu mantýk olarak parametre olarak tamýnladýðýmýz x deðerini dizinin son elemaný olarak ekler
{
	if(array==NULL)//dizimiz boþsa
	{
		int *array=(int*)malloc (sizeof(int )*size/2);//dizimiz boþsa boyutu yarýya indirilmiþ bir kutu oluþturulur
	}
	if(top>=size)//eðer boyut tepe noktamýzdan büyük olursa (dizimizin boyutu büyümüþ ve onu baþka bir diziye atmamýz gerekir)
	{
		int *arrayTemp=(int*)malloc (sizeof(int )*size*2);//dizitakas adýnda ,dizi adý verdiðimiz dizimizin 2 katý olacak bir kutu oluþturuyoruz
		int i=0;//for için i deðiþkeni tanýmladýk
		for(i=0;i<size;i++)//i=0 daþlayarak 1 er 1 er artarak ve boyut sayýsýnda son bulacak þekilde tanýmlanýr
		{
			arrayTemp[i]=array[i];//yeni ve daha büyük olan dizimiz dizi takasa her adýmda ilk dizimizdeki verileri atarýz		
		}
		free(array);//artýk iþimize yaramayacak dizi deðiþkenimizi ram den sileriz
		array=arrayTemp;//dizitakasý diziye atarýz
		size*=2;//boyutu 2 ile arttýrýz
	}
	array[top++]=x;//push iþlemini saðlamasý için dizimize girilen x deðerini ekleriz(dizimizin sonuna)
}
void arrayPrint()//her zaman olmasý gereken yazdýrma fonk.
{
	
	int i=0;
	printf("Boyut : %d\n",size);//boyutumuzun deðiþimini görmek için yazdýrdýk ve for döngüsü için i tanýmladýk
	for(i=0;i<top;i++)//i=0 daþlayarak 1 er 1 er artarak ve boyut sayýsýnda son bulacak þekilde tanýmlanýr
	{
		printf("%d \n",array[i]);//dizimiz deðerini her seferinde bir satýr atlayarak yazdýrdýk
	}
	printf("\n");//bir satýr atladýk
}
int main(int argc, char *argv[]) {
	array=(int*)malloc(sizeof(int)*2);//dizi deðiþkenimizi bir kutu oluþturarak çaðýrdýk
	push(10);//10 ekledik
	push(20);//20 ekledik
	push(30);//30 ekledik
	push(40);//40 ekledik
	push(50);//50 ekledik
	arrayPrint();//yazdýrdýk
	pop();//Pop iþlemi yaparak çýkarttýk
	pop();//Pop iþlemi yaparak çýkarttýk
	pop();//Pop iþlemi yaparak çýkarttýk
	pop();//Pop iþlemi yaparak çýkarttýk
	pop();//Pop iþlemi yaparak çýkarttýk
	arrayPrint();//yazdýrdýk
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
	arrayPrint();//yazdýrdýk
	return 0;
	getch();
}
