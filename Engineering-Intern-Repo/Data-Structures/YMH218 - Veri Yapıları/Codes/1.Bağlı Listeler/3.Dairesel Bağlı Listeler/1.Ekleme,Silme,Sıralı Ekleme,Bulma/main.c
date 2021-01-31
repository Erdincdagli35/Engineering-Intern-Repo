#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
struct n{ //n adýnda bir yapý oluþturduk
	int x;struct n*next;
	//Herhangibir x deðeri ve x deðerinin sonrasý için next i tanýmladýk
};
typedef struct n node;//
void printArray(node * r)//r olarak tanýmlanmýþ pointerla printArray adýnda method oluþturduk
{	node*iter=r;//dairesel olduðu için roota dönmesi lazým tekrar
	printf("%d ",iter->x);//r pointerin datasýný yazdýr.
	iter=iter->next;//bir sonraki dataya geç
	while(iter!=r)//eðer r pointer ý boþ deðilse yazdýrma iþlemi yap
	{
		printf("%d ",iter->x);//r pointerin datasýný yazdýr.
		iter=iter->next;//bir sonraki dataya geç
	}
	printf("\n");//bir satýr aþaðýya indik	
}
node* arraySequentialAdding(node *r,int x)//her zamanki gibi r pointerý ve x deðiþneinin paramtre olarak tamýnladýk
{
	
	if(r==NULL)//eðer listemiz boþsa
	 {
	 	r=(node*)malloc(sizeof(node));//bir data oluþturacak
		r->next=r;//datamýzýn kuyruðunu Null yapacaðýz devamlýlýðý saðlamak için
		r->x=x;	//ve ilk datamýzýn deðerini gireceðiz
		return r;//ve bu datayý döndereceðiz
	 }
	 if(r->x>x)//ilk elemandan küçük durumu kontol ediyoruz(buna ayný zamamda baþa ekleme diyebiliriz)
	 	{//root deðiþiyor(root datasýnýn bir içinde bir deðeri oluyor)
	 		node*temp=(node*)malloc(sizeof(node));//her zaman ki gibi kutu oluþturuyoruz
			temp->x=x;//oluþturduðumuz kutuya deðerimizi atýyoruz
			temp->next=r;//temp datasýnýn kuyruðu r pointerýna eþit olamýlýdýr
			node*iter=r;//düðüm olarak tanýmladýðýmýz iter pointerýný r ye eþitledik
			while(iter->next!=r)//mantýken itein kuyruðu r ye eþit olamdýðý sürece
				iter=iter->next;//listede dönecek
			iter->next=temp;//aksi taktirde temp datasý iterin kuyruðuna eþitlenecek
			return temp;//temp datasý dönderilecek
			}	
	 node*iter =r;//r pointerýmýzý iter pointerýna eþitledik
	 while(iter->next!=r&&iter->next->x<x){//eðer ilk deðer ikinci deðerden küçükse(bu durum doðrudur) ve iter pointerýnýn kuyruðu boþ deðilse
	 	iter=iter->next;//iter pointerýnýn kuyruðu itere eþitolacaktýr.(liste içinde dolaþmalýyýz) iþlem yapadan devam etmeliyiz yani
	 }
	 node*temp=(node*)malloc(sizeof (node));//eðer while döngünü karþýlamazsa bir kutu oluþturacaktýr.
	 temp->next=iter->next;//ortaya eklemede yaptýðýmýz ayný mantýkta ilk olarak iterin kuyruðunu temp in kuyurðuna baðlarýz
	 iter->next=temp;//temp i de iterin kuyruðuna baðlarýz(bu kod her zaman bi önceki kodtan sonra yazýlmalýdýr.)yoksa liste baðlantýsý kopar
	 temp->x=x;//temp datamýza istediðimz deðeri yazýrýyoruz
	 return r;//son olarak r yi dönderiyoruz
	 
	 }
	node * removeArrayElement(node* r,int x)//her zaman olduðu gibi r pointerý ve x deðerini parametre olarak baþladýk
	{
		node * temp;//temp pointerýný düðümden ekledik
		node * iter=r;//iter pointerýný r pointerýna eþitledik
		if(r->x==x)//r nin data deðeri x deðerine eþitese orda duracak ve
		{	while(iter->next!=r)//iterin kuyruðu r pointerýna eþit deðilse
			{
				iter=iter->next;//listede gezsin
			}
			iter->next=r->next;//r nin kuyruðu iterin kuyruðuna eþitleriz
			free(r);//r yi ram den sileriz
			return iter->next;//son olarak iter in kuyruðunu döndereceðiz
		}
		while(iter->next!=r && iter->next->x!=x)//iter pointerýmýzýn kuyruðu boþ deðilse ve iterin kuyruðunun deðeri boþ deðilse döngümüz dönecek
		{
			iter=iter->next;//her zaman yaptýðýmýz gibi devamlýlýk için bu kodu kullanmalýyýz
						
		}
		if(iter->next==r)//eðer iterin kuyruðu r ye eþitse
		{	
			printf("\nSayi Bulunamadi !!\n");
			return r;//sayý bulunamadý
			
		}
		temp=iter->next;//hiçbir sorguyu karþýlamýyorsa iterin kuyruðu tempe eþitledik
		iter->next=temp->next;//iter->next=iter->next->next þekilde de yazabiliriz temp=iter->next eþit olduðu için öyle yazýk
		free(temp);//ramden temp datasýný temizledik
		return r;//r datasýný dönderdik
	}
	void addingElement(node*r,int x)//ekleme metodu için pointer r ve int deðerinde x i parametre olarak tanýmladýk
	{
		node * iter=r;//düðüm iter pointer olarak tanýmlanýp r ye eþitlendi
		while(iter->next!=r)//iterin kuyruðu r pointerýna eþit deðilse 
		{
			iter=iter->next;//listede dolaþ
		}
		iter->next=(node*)malloc(sizeof(node));//bir kutu oluþtur
		iter->next->x=x;//iterin kuyruðuna istenilen veriyi yazdýr
		iter->next->next=r;//iterin kuyruðunun kuyruðuna r yi ata 
	}
int main(int argc, char *argv[]) {
	node * root;//kök datasýný düðümden pointer olarak atýyoruz
	root=NULL;//root datamýzý boþ tanýmlýyoruz
	root=arraySequentialAdding(root,40);//kök datalý 400 sayýsýný ekliyoruz
	root=arraySequentialAdding(root,4);//kök datalý 40 sayýsýný ekliyoruz
	root=arraySequentialAdding(root,4000);//kök datalý 4 sayýsýný ekliyoruz
	root=arraySequentialAdding(root,450);//kök datalý 450 sayýsýný ekliyoruz
	root=arraySequentialAdding(root,50000 );//kök datalý 500 sayýsýný ekliyoruz
	printArray(root);//kök bazlý yazýrma methodunu kullanýyoruz
	root=removeArrayElement(root,50);//kök datalý 50 deðeri olan datayý silmeye çalýþtýk
	printArray(root);//kök bazlý yazýrma methodunu kullanýyoruz
	root=removeArrayElement(root,999);//kök datalý 999 deðeri olan datayý silmeye çalýþtýk
	printArray(root);//kök bazlý yazýrma methodunu kullanýyoruz
	root=removeArrayElement(root,4);//kök datalý 4 deðeri olan datayý sildik
	printArray(root);//kök bazlý yazýrma methodunu kullanýyoruz
	root=removeArrayElement(root,450);//kök datalý 450 deðeri olan datayý sildik
	printArray(root);//kök bazlý yazýrma methodunu kullanýyoruz
	
	/*Açýklama : Genel olarak Dairesel baðlý listeden çýkarýlan sonuç:
		Baðlý liste olan : kuyruðun her zaman null u göstermesi dairesel listede ilk datayý gösterir
		bütün olay bu mantýkla tekrardan baðlý liste üzerinde yapýp güncellenerek Dairesel Baðlý liste oluþturulur.
		
	*/
	return 0;
	getch();
}
