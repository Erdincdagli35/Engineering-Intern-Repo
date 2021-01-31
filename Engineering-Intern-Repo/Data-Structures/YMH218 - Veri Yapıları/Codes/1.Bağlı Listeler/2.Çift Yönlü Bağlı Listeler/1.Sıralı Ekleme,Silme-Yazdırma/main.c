#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
struct n{ //n adýnda bir yapý oluþturduk
	int x;struct n*next;struct n*prev;//x in öncesi için prev tanýmladýk
	//Herhangibir x deðeri ve x deðerinin sonrasý için next i tanýmladýk 
	
};
typedef struct n node;//
void printArray(node * r)//r olarak tanýmlanmýþ pointerla printArray adýnda method oluþturduk
{
	while(r!=NULL)//eðer r pointer ý boþ deðilse yazdýrma iþlemi yap
	{
		printf("%d \n",r->x);//r pointerin datasýný yazdýr.
		r=r->next;//bir sonraki dataya geç
	}
	printf("\n");	
}
node* arraySequentialAdding(node *r,int x)//her zamanki gibi r pointerý ve x deðiþneinin paramtre olarak tamýnladýk
{
	if(r==NULL)//eðer listemiz boþsa
	 {
	 	r=(node*)malloc(sizeof(node));//bir data oluþturacak
		r->next=NULL;//datamýzýn kuyruðunu Null yapacaðýz devamlýlýðý saðlamak için
		r->prev=NULL;
		r->x=x;	//ve ilk datamýzýn deðerini gireceðiz
		return r;//ve bu datayý döndereceðiz
	 }
	 if(r->x>x)//ilk elemandan küçük durumu kontol ediyoruz(buna ayný zamamda baþa ekleme diyebiliriz)
	 	{//root deðiþiyor(root datasýnýn bir içinde bir deðeri oluyor)
	 		node*temp=(node*)malloc(sizeof(node));//her zaman ki gibi kutu oluþturuyoruz
			temp->x=x;//oluþturduðumuz kutuya deðerimizi atýyoruz
			temp->next=r;//temp datasýnýn kuyruðu r pointerýna eþit olamýlýdýr
			r->prev=temp;
			return temp;//son olarak temp datasýný dönderiyoruz
		}	
	 node*iter =r;//r pointerýmýzý iter pointerýna eþitledik
	 while(iter->next!=NULL&&iter->next->x<x){//eðer ilk deðer ikinci deðerden küçükse(bu durum doðrudur) ve iter pointerýnýn kuyruðu boþ deðilse
	 	iter=iter->next;//iter pointerýnýn kuyruðu itere eþitolacaktýr.(liste içinde dolaþmalýyýz) iþlem yapadan devam etmeliyiz yani
	 }
	 node*temp=(node*)malloc(sizeof (node));//eðer while döngünü karþýlamazsa bir kutu oluþturacaktýr.
	 temp->next=iter->next;//ortaya eklemede yaptýðýmýz ayný mantýkta ilk olarak iterin kuyruðunu temp in kuyurðuna baðlarýz
	 iter->next=temp;//temp i de iterin kuyruðuna baðlarýz(bu kod her zaman bi önceki kodtan sonra yazýlmalýdýr.)yoksa liste baðlantýsý kopar
	 temp->prev=iter;//iter i temp datasýnýn öncesine eþitledik
	 if(temp->next!=NULL)//eðer tempin kuyruðu boþ deðilse 
	 	temp->next->prev=temp;//temp i temp datasýnýn kuyruðunun öncesine ata
	 temp->x=x;//temp datamýza istediðimz deðeri yazýrýyoruz
	 return r;//son olarak r yi dönderiyoruz
	 
	 }
	 node* arrayDelete(node *r ,int x)//silme fonk. r pointerý ve int tanýmlanan x ten oluþmuþtur
	 {
	 	node * temp;//düðümde temp pointerýný tanýmladýk
	 	node*iter=r;//iter pointerýnýn r ye eþitledik
	 	
	 	if(r->x==x)//r pointerý deðeri x deðerine eþitese
	 	{
	 		temp=r;//r yi tempe atadýk
	 		r=r->next;//r nin kuyruðunu r ye atadýk 
	 		free(temp);//ram den temp i sildik
	 		return r;//r yi dönderdik
		}
		while(iter->next!=NULL && iter->next->x!=x){//daha önce dediðimiz gibi ayný þekilde bu sorgu saðlandýðý sürec
		 	iter=iter->next;//listede dönecek
		}		 	
		if(iter->next==NULL)//iterin kuyruðu boþsa
		{
			printf("\nSayý Bulunamadý\n");
			return r;//r yi dönder
		}
		temp=iter->next;//iterin kuyruðu tempe atadýk
		iter->next=iter->next->next;//iterin kuruðunun kuyruðunu iterin kuyuruðuna atadýk
		free(temp);//ram  den tempi sildik
		if(iter->next!=NULL)//iterin kuyruðu boþ deðilse
			iter->next->prev=iter;//iteri iterin kuyruðunun öncesine ata
		return r;//r yi dönder
	 }
int main(int argc, char *argv[]) {
	node * root;//kök datasýný düðümden pointer olarak atýyoruz
	root=NULL;//root datamýzý boþ tanýmlýyoruz
	root=arraySequentialAdding(root,400);//kök datalý 400 sayýsýný ekliyoruz
	root=arraySequentialAdding(root,40);//kök datalý 40 sayýsýný ekliyoruz
	root=arraySequentialAdding(root,4);//kök datalý 4 sayýsýný ekliyoruz
	root=arraySequentialAdding(root,450);//kök datalý 450 sayýsýný ekliyoruz
	root=arraySequentialAdding(root,50 );//kök datalý 500 sayýsýný ekliyoruz
	printArray(root);//kök bazlý yazýrma methodunu kullanýyoruz
	root=arrayDelete(root,50);//kök datalý 50 sayýsýný bulup silmeye çalýþýyoruz
	printArray(root);//kök bazlý yazýrma methodunu kullanýyoruz
	root=arrayDelete(root,999);//kök datalý 999 sayýsýný bulup silmeye çalýþýyoruz
	printArray(root);//kök bazlý yazýrma methodunu kullanýyoruz
	root=arrayDelete(root,4);//kök datalý 4 sayýsýný bulup silmeye çalýþýyoruz
	printArray(root);//kök bazlý yazýrma methodunu kullanýyoruz
	root=arrayDelete(root,450);//kök datalý 450 sayýsýný bulup silmeye çalýþýyoruz
	printArray(root);//kök bazlý yazýrma methodunu kullanýyoruz
	
	return 0;
	getch();
}
