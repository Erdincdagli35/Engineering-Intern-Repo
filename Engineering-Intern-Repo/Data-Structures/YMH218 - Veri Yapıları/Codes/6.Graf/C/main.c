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
				printf("%d ile %d arasýnda kenar var ise 1 yoksa 0 giriniz\n",i,j);
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
	printf("Graph Ýçin Maksimum Düðüm Sayýsýný Giriniz : (Max = %d ) : ",MAX);
	scanf("%d",&n);
	build(adj,n);
	for(i=0;i<n;i++)
	{
		printf("\n%d Indegree düðüm sayýsý %d dýr ",i,indegree(adj,i,n));
		printf("\n%d Outdegree düðüm sayýsý %d dýr ",i,outdegree(adj,i,n));
		
	}
	return 0;
	getch();
	
}
