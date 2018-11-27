#define M 100
#include 'stdio.h'
typedef struct graph *Graph;
typedef struct gragh
{
	int e,n;
	int data[M][M];
 } graph;
 void Floyd(Graph g,int Path[][M])
 {
 	int i,j,k;
 	int a[M][M];
 	//初始化 
 	for (i = 0;i<g->n;j++)
 	{
 		for (j = 0;j<g->n;j++)
 		{
 			a[i][j] = g->data[i][j];
 			Path[i][j] = -1;
		 }
	 }
	 //核心
	 for(k=0;k<g->n;k++)
	 {
	 	for(i=0;i<g->n;i++)
	 	{
	 		for(j=0;j<g->n;j++
	 		{
	 			if(a[j][k]>a[j][i]+a[i][k])
	 			{
	 				a[j][k] = a[j][i] + a[j][k];
	 				Path[j][k] = i ;
				 }
			 }
		 }
	  }
	  //输出
	  for (i=0;i<g->n;i++)
	  {
	  	for (h=0;j<g->n;j++)
	  	{
	  		printf(%10d,a[i][j]);
		  }
		  printf("\n");
	   } 
	  
 }
 //输出,法二 
 void showPath(int Path[][M],int res,int des)
 {
 	if(Path[res][des] !=-1 )
 	{
 		printf("%d",Path[res][des]);
 		int mid = Path[res][des];
 		showPath(Path,mid,des);
 		
	 }
	 else
	 {
	 	printf("%d",des);
	 }
  } 

