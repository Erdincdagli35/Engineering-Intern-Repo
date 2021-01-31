#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
/* A:ÝkiliAðaç
	Özyineli(Recursive) Tanýmý
	1.Boþ Olabilir
	2.Ýki çocuðunda da ikili aðaç olan (subtree)düðüm
	3.1 ve 2 li yapýlarýn sonlu uygulanmasýyla elde edilen yapýdýr 
   B:Ýkili Arama Aðacý
    -Belli bir sayý sýrlamasýnýn aðaca yerleþtirilmiiþ halidir	
 */
struct node{//düðümümüzü sturct yapýsýnda tanýmladýk
	struct node*left;//left deðikeni sol
	struct node*right;//right deðiþkeni sað için
	int x;//x ifadeside gelen sayý için
};
struct node*adding(struct node*tree,int x)//ekleme modlünü oluþturmak için x deðerini istedik parametre olarak
{
	if(tree==NULL)//eðer aðacýmýz boþ ise
	{
		struct node*root=(struct node*)malloc(sizeof(struct node));//root adýnda bir kutu oluþturacaðýz
		root->left=NULL;//rootun solunu null
		root->right=NULL;//saðýn null yyapýcaz
		root->x=x;//rootun datasýna x yazacaðýz
		return root;//root u döndereceðiz
	}
	if(tree->x<x)//eðer aðacýn datasý girilen x deðerinden küçükse
	{		tree->right=adding(tree->right,x);//(recursive fonk kullanýlarak) aðacýn saðýna ekleyeceðiz
			return tree;// ve aðacý döndereceðiz
	}
	tree->left=adding(tree->left,x);//deðilse aðacýn soluna ekleyip
	return tree;//ayný þekilde aðacý döndereceðiz
	
}
void infix(struct node*tree)//infix gezinme metodu (Left-Tree-Right) mantýðý kýullanýlýr
{	
	if(tree==NULL)//eðer aðaç boþ ise
	{
		return;//boþ deðer dönder
	}//deðilse
	infix(tree->left);//ilk (LTR) mantýðýndan lefti yazdýr
	printf("%d\n",tree->x);//sonra kök ü
	infix(tree->right);//sonrada right ý dönder
}
void postfix(struct node*tree)//postfix gezinme metodu(Left-Right-Tree) mantýðý kullanýlýr
{
	if(tree==NULL){//eðer aðaç boþsa 
		return;//boþ deðer dönder
	}//deðilse(recursive fonk. ile)
	postfix(tree->left);//ilk sol u yazdýr
	postfix(tree->right);//sonra saðý yazdýr
	printf("%d \n",tree->x);//kök ü yazdýr
}
void prefix(struct node*tree)//prefix gezinme methodu ise (Tree-Left-Right) mantýðý ile çalýþýr
{
	if(tree==NULL)//eðer aðaç boþsa  
	{
		return;//boþ deðer dönder
	}
	printf("%d \n",tree->x);//ilk kökü yazýdr
	prefix(tree->left);//sonra solu
	prefix(tree->right);//sonra saðý yazýdr
}
int find(struct node*tree,int a)//Bulma fonk için a deðikeni tanýmlamýz yeterli olacaktýr parametre olarak
{
	if(tree==NULL)//aðaç boþsa 
	{
		return -1;//-1 deðerini dönder
	}
	if(tree->x==a)//aðacýn datasý a deðerine eþitse
	{
		return 1;//1 deðerini dönder
	}
	if(find(tree->right,a)==1)//eðer aðacýn saðýnda a deðerine 1 eþitse 
		return 1;//1 dönder
	if(find(tree->left,a)==1)//eðer aðacýn solunda a deðerine 1 eþitse
		return 1;//1 dönder
	return -1;//akis halde yine -1 dönder
	
}


struct node*del(struct node*tree,int x){//silme metodu için x deðerini parametre olarak tanýmladýk
	if(tree==NULL)//aðaç boþsa 
	{
		return NULL;//boþ deðer dönder
	}
	if(tree->x==x){//aðacýn datasý x eþitse
		if(tree->left==NULL&&tree->right==NULL)//eðer aðacýn solu boþsa ve aðacýn saðýda boþsa 
			return NULL;//boþ deðer dönder
		if(tree->right!=NULL){//eðer aðacýn saðý boþ deðilse
			tree->x=min(tree->right);//saðdaki aðacýnýn minimum deðerini aðacýn x datasýna yaz
			tree->right=del(tree->right,min(tree->right));//aðacýn en küçük sað deðerini aðacýn saðýna ata
			return tree;//aðacý dönder
		}//deðilse
		tree->x=max(tree->left);//aðacýn solunun en büyük deðeri aðacýn deðerine ata 
		tree->left=del(tree->left,max(tree->left));//soldaki aðacýn maximum deðerini soldaki aðaca yaz
		return tree;//aðacý dönder
	}
	if(tree->x<x)//aðacýn datasý x girilen x deðerinde küçükse
	{
		tree->right=del(tree->right,x);//sað aðactaki deðeri sil aðacýn saðý siil
		return tree;//aðacý dönder
	}//deðilse
	tree->left=del(tree->left,x);//sol aðactaki deðeri sol aðacaný solu sil
	return tree;//aðacý dönder
}
int max(struct node*tree)//aðactaki max deðeri bulmak için 
{
	while(tree->right!=NULL)//aðacýn saðsaki deðeri boþ deðilse
	{//saðda dolaþmamýzýn mantýðý en büyük eleman hep saðda olur
		tree=tree->right;//aðacýn saðýnda dolaþ
	}
	return tree->x;//aðacýn datasýný dönder
}
int min(struct node*tree)//aðaçtaki min deðerini bulmak için
{
	while(tree->left!=NULL)//aðacýn solu boþ deðilse
	{//solda dolaþmamýzýn sebebi aðacýn solu en küçük deðer olur
		tree=tree->left;//solu dolaþ
	}
	return tree->x;//aðacýn datasýný yazdýr
}
int leaves(struct node * tree)
{
	int s=0,sLeft=0,sRight=0;
	infix(tree);
	while(tree->left!=NULL)
	{
		//tree=tree->left;
		if(tree->left==NULL && tree->right==NULL)
		{
			sLeft++;
		}
		
	}
	while(tree->right!=NULL)
	{
		//tree=tree->right;
		if(tree->left==NULL && tree->right==NULL)
		{
			sRight++;
			
		}
	}
	s=sLeft+sRight;
	return sLeft;
}
int main(int argc, char *argv[]) {
	struct node*tree=NULL;
	/*tree=adding(tree,56);
	tree=adding(tree,200);
	tree=adding(tree,26);
	tree=adding(tree,190);
	tree=adding(tree,213);
	tree=adding(tree,18);
	tree=adding(tree,28);
	tree=adding(tree,12);
	tree=adding(tree,24);
	tree=adding(tree,27);
	infix(tree);printf("------------------------\n");
	postfix(tree);printf("------------------------\n");
	prefix(tree);
	//printf("\nArama Sonucu : %d ",find(tree,24));
	printf("\nEn buyuk eleman : %d",max(tree));
	printf("\nEn kucuk eleman : %d\n",min(tree));
	tree=del(tree,56);
	infix(tree);*/
	tree=adding(tree,2);
	tree=adding(tree,3);
	tree=adding(tree,4);
	tree=adding(tree,5);
	tree=adding(tree,7);
	tree=adding(tree,8);
	/*tree=adding(tree,1);
	tree=adding(tree,15);
	tree=adding(tree,13);
	tree=adding(tree,14);*/
	infix(tree);printf("En Büyük : %d\nEn Küçük : %d\nYaprak Sayýsý : %d",max(tree),min(tree),leaves(tree));
	//leaves(tree);
	return 0;
	getch();
}
