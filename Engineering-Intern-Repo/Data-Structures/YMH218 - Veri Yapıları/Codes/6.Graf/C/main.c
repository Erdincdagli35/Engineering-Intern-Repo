#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define MAX 10
void build(int adj[][MAX],int n)
	{
	
	int i,j;
	for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++	)
			{
				printf("%d ile %d aras�nda kenar var ise 1 yoksa 0 giriniz\n",i,j);
				scanf("%d",&adj[i][j]);
			}
		}
	}
int outdegree(int adj[][MAX],int x,int n)
{
	int i,count=0;
	for(i=0;i<n;i++)
	{
		if(adj[x][i]==1)
		{
			count++;
			return(count);
		}
	}
}
int indegree(int adj[][MAX],int x,int n)
{
	int i,count=0;
	for(i=0;i<n;i++)
	{
		if(adj[i][x]==1)	
		{
			count++;
			return(count);
		}
	}
}
int main(int argc, char *argv[]) {
	int adj[MAX][MAX],node,n,i;
	printf("Graph ��in Maksimum D���m Say�s�n� Giriniz : (Max = %d ) : ",MAX);
	scanf("%d",&n);
	build(adj,n);
	for(i=0;i<n;i++)
	{
		printf("\n%d Indegree d���m say�s� %d d�r ",i,indegree(adj,i,n));
		printf("\n%d Outdegree d���m say�s� %d d�r ",i,outdegree(adj,i,n));
		
	}
	return 0;
	getch();
	
}
