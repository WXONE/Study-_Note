#include <stdio.h>
#include <stdlib.h>
#define M 20 //宏定义MAXSIZE
#inlclude <string.h>
 typedef struct node
{
	int adjvex;//边表结点 
	struct node *next;//邻接点 
	
 } edgenode;
 typedef struct vnode
 {
 	char vertex;//顶点信息 
	edgenode *firstedge;
 }vertexnode;
 typedef struct 
 {
 	vertexnode adjlist[M];//存放头结点的链表
	 int n,e;//图的顶点数与边数 
	  
 }linkedgraph;
