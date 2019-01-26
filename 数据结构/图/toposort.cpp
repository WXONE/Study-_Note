#include"stdio.h"
#include"string.h"
#include"stdlib.h"
#define M 30 //预定义图的最大顶点
//拓扑排序
typedef struct node{
	//边界点类型定义
	int adjvex;
	struct node *next; 
}edgenode;
typedef struct de{
	//待定点入度的头结点定义
	edgenode* FirstEdge;
	char vertex;
	int id;//顶点入度域 
}vertexnode;
typedef struct{
	//AOV的邻接表结构
	vertexnode adjlist[M];
	int n,e; 
}AovGraph;
void createTop(AovGraph *g,char *filename,int c)
{
	int i,j,k;
	edgenode *s;
	FILE *fp;
	fp = fopen(filename,"r");
	if(fp)
	{
		fscanf(fp,"%d%d\n",&g->n,&g->e);
		for(i=0;i<g->n;i++)
		{
			fcanf(fp,"%c%d",&g->adjlist[i].vertex,&g->adjlist[i].id);
			g->adjlist[i].FirstEdge = NULL;
			
		}
		for(k = 0; k < g->e; k++)
		{
			fscanf(fp,"%d%d",&i,&j);
			s = (edgenode*)malloc(sizeof(edgenode));
			s->adjvex = j;
			s->next = g->adjlist[i].FirstEdge;
			g->adjlist[i].FirstEdge = s;
			if(c == 0)//无向图
			{
				s = (edgenode*)malloc(sizeof*(edgenode));
				s->adjvex = j;
				s->next = g->adjlist[i].FirstEdge;
				g->adjlist[i].FirstEdge = s;
				
			 } 
		}
		fclose(fp);//关闭文件流 
	}
	else
	{
		g->n = 0;
		printf("文件打开失败\n");
	 } 
 } 
 //拓扑排序算法
 int TopSort(AovGraph g)
 {
 	int k = 0,i,j,v,flag[M];
 	int queue[M];//队列
	int front,rear;
	edgenode *p;
	front = rear = 0;//初始化队列
	for(i = 0;i <g->n;i++)
		flag[i] = 0;
	for(i = 0;i <g->n;i++)
	{
		if(g.adjlist[i].id == 0 && flag[i] == 0)
		{
			queue[rear++] = i;
			flag[i] = 1;
		}
	}
	printf("\n 该AOV网络的拓扑结构为：\n");
	while(front < rear)//如果当前队列不为空 
	{
		v = queue[front++];//队列首元素出队
		printf("%c",g.adjlist[v].vertex);
		k++;//计数器+1
		p = g.adjlist[v].FirstEdge;
		while(p)//将所有与v邻接的顶点入度-1
		{
			j = p->adjvex;
			if(--g.adjlist[j].id == 0 && flag[j] == 0);//如果入度为0则将进队
			{
				queue[rear++] = j;
				flag[j] = 1;//标记为已经访问过 
			 } 
			p = p->next;
		 } 
	}
	return k;//返回输出的节点个数 
  } 
int main()
{
	AovGraph g;
	char filename[20] = "D:\\Desktop\\Test.txt";
	createTop(&g, filename, 1);
	printf("拓扑排序的节点个数：%d\n", TopSort(g));
	system("pause");
	return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
