#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
struct node{//struct olarak bir düðüm oluþturduk
	struct node*next;//düðümün kuyruðu için next i ekledik
	int x;//x deðiþenin tanýmladýk
};
void listPrint(struct node*root)//listemizi yazdýrmak için struct node * root pointerýný struct düðümünden aldýk
{
	struct node*iter=root;//düðümüden iter pointerýný itere eþitledik
	int i =0;//for için i=0 tanýmladýk
	while(iter!=NULL)//iter boþ deðilse
	{
		
		printf("%d \n",iter->x);//iter->x yani deðerimizi yazdýr ve bir satýr aþaðýya in 
		iter=iter->next;//listede dolaþ
	} 
}
struct node* push(struct node*root,int x)//eklemek için x deðerine ihtiyacýmýz var bu þekilde tanýmladýk fonk.
{
	if(root==NULL)//kök pointerý boþsa
	{
		root=(struct node*)malloc(sizeof(struct node));//bir kutu oluþtur
		root->x=x;//kutuya istediðimiz(x) deðerini ekle
		root->next=NULL;//kök pointerýn kuyruðunu boþ yap(baðlý liste mantýðýndan geliyor)
		return root;//son olarak root u dönder
	}
	struct node *iter =root;//iter pointerýný roota eþitle 
	while(iter->next!=NULL)//eðer iterin kuyruðu boþ deðilse 
	{
		iter=iter->next;//her baðlý listede olduðu gibi bu durumdada dolaþacak
	}
	iter->next=(struct node*)malloc(sizeof(struct node));//deðilse iterin kuyruðuna bir kutu oluþturacak
	iter->x=x;//kutunun içine istenilen deðer girilicek
	iter->next->x=x;//ayný þekilde kuyruðuna da istenilen deðer girilicek
	iter->next->next=NULL;//kuyruðunun kuyruðu ise boþ olacak (baðlý liste mantýðýndan)
	return root;//son olarak root u dönder
	
}
struct node* pop(struct node*root){//pop (listeden çýkarma iþlemi için struct þeklide tanýmlanýr)
	if(root->next==NULL)//root un kuyruðu boþsa
	{
		root=NULL;//root ta boþ olmalýdýr
		return root;//root u döndermelidir
	}
	if(root==NULL)//eðer root boþsa
	{
		printf("Stack Boþ");//ekrana stock boþ bastýrýlýr
		return root;//root dönderilir
	}
	else{//deðilse
		struct node*iter=root;//iter pointerý root a eþitlenir 
		while(iter->next->next!=NULL)//eðer iterin kuyruðunun kuyruðu boþ deðilse
		{
			iter=iter->next;//listede dolaþýr
		}	
		iter->next=NULL;//iterýn kuyruðunu boþ yapar (b.liste mantýðý)
		return root;//root dönderilir
	}
	
}

int main(int argc, char *argv[]) {
	struct node*root=NULL;//boþ bir root pointerý tanýmlanýr
	int i;//for için i tanýmlanýr
	for(i=0;i<10;i++)//1 den 10 kadar eklenemesi i.in for açýlýr
	{
		root=push(root,i*5);//yazdýðýmýz push methodunu root pointerý yardýmýyla kullanarak 5 in katlarýný ekleriz
	}
	listPrint(root);//root bazlý yazdýrma iþlemi yaparýz
	printf("Pushladýk\n------------------------------------\n");//ekrana yazdýrýrýz
	for(i=0;i<5;i++)//1den 5 e kadar pop metoduyla çýkarmaya çalýþýrýz
	{
		root=pop(root);//son eklenenden ilk eklenene doðru çýakrýz
	}
	listPrint(root);//root bazlý ekrana bastýrýz
	printf("Popladýk\n------------------------------------\n");//ekrana yazdýrýrýz
	return 0;
	getch();
}
