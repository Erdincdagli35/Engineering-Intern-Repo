#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
struct node{
	int x;
	struct node*next;

};
struct node * root=NULL;
struct node*last=NULL;	
struct node* enqueue(struct node*root,int x)
{
	if(root==NULL)
	{
		root=(struct node*)malloc(sizeof(struct node));
		root->x=x;
		root->next=NULL;
		last=root;
		return root;
		
	}
	else{
		last->next=(struct node*)malloc(sizeof(struct node));
		last->next->x=x;
		last=last->next;
		last->next=NULL;
		return last;
	}
}
int dequeue(struct node*root){
	
	if(root==NULL)
	{
		printf("Link List Bos");
		return -1;
	}
	int rvalue=root->x;
	struct node*temp=root;
	root=root->next;
	free(temp);
	return rvalue;
		
		
}
void write(struct node*root)
{
	struct node*iter=root;
	while(iter!=NULL)
	{
		printf("%d \n",iter->x);
		iter=iter->next;
	}
}
int main(int argc, char *argv[]) {
	struct node*iter=root;enqueue(root,11);
	enqueue(root,12);
	enqueue(root,13);
	
	write(root);
	return 0;
	getch();
}
