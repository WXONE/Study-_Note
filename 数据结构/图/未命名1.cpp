#include <stdio.h>
#include <stdlib.h>
#define M 20 //�궨��MAXSIZE
#inlclude <string.h>
 typedef struct node
{
	int adjvex;//�߱��� 
	struct node *next;//�ڽӵ� 
	
 } edgenode;
 typedef struct vnode
 {
 	char vertex;//������Ϣ 
	edgenode *firstedge;
 }vertexnode;
 typedef struct 
 {
 	vertexnode adjlist[M];//���ͷ��������
	 int n,e;//ͼ�Ķ���������� 
	  
 }linkedgraph;
