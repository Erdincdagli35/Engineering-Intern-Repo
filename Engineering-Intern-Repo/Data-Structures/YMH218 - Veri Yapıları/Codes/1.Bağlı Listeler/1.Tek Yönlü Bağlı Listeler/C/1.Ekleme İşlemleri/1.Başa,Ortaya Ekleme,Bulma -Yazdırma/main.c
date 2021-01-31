#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
struct n{ //n adýnda bir yapý oluþturduk
	int x;struct n*next;
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
}
void addingArrayRight(node* r,int x)//son ekleme yapabilmesi için pointer ve x deðeri tanýmladýk paramaetre olarak
{
	while(r->next!=NULL){//eðer r pointerýnýn kuyruðu boþ deðilse 
		r=r->next;//diðer datadan devam et
	}
	r->next=(node*)malloc(sizeof(node));//boþsa bir kutu oluþtur.(r pointerýnýn kuyruðunda)
	r->next->x=x;//r pointeýnýn sonuna x i ekle
	r->next->next=NULL;//x sonrasýnýn sonrasý Null ata ki devamlýlýk saðlanabilsin
	
}
void addingArrayMiddle(node*iter,int x,int index)//Ortaya ekleme yapabilmek için iter pointerý,eklenecek x deðeri,ve silinecek yer için index deðeri tanýmladýk
{
	node*root;//kök düðümü poiter olarak gösterdik
	int i=0;//i deðiþkenini tanýmladýk
	for(i=0;i<=index-2;i++)//for döngümüyüzü açtýk 
	{
		iter=iter->next;//durmamýz gereken yere kadar datalarýn arasýnda gezinmemizi saðlayacak
	}
	node*temp=(node*)malloc(sizeof(node));//daha kolay iþlem yapabilmek için temp adýnda data oluþturduk
	temp->next=iter->next;//(Her zaman öncelikli olarak bunu yapmalýyýz)tempin kuyruðuna iterin kuyruðunu baðladýk
	iter->next=temp;//temp i de iterin kuyruðuna baðlayarak kamçýlama iþlemi yapýp araya kutuyu eklemiþ olduk
	temp->x=x;//son olarakta temp datamýzýn içine girilmesi istenilen deeðeri yazdýrdýk
}

int main(int argc, char *argv[]) {
	node * root;//kök düðümü oluþtur.
	root=NULL;
	root=(node*)malloc(sizeof(node));//bir data(kutu) oluþtur.
	root->x=50;//kök datasýna 50 deðerini ata (bu mutlaka yapýlamalýdýr.Program çalýþmaz aksi durumda) 
	root->next=NULL;//kök datasýnýn kuyruðuna Null ata ki devamlýlýðý saðlayabilsin
	addingArrayRight(root,33);//sona ekleme yaptýk
	addingArrayRight(root,44);//sona ekleme yaptýk
	addingArrayRight(root,55);//sona ekleme yaptýk
	addingArrayMiddle(root,11,3);//11 deðerini 3 datadan sonra ekledik.
	addingArrayMiddle(root,66,2);//66 deðerini 2 datadan sonra ekledik
	printArray(root);//datalarýmýzý yazdýrdýk.
	return 0;
	getchar();
}
