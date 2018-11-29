#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define M 20//Ԥ����ͼ����󶥵���
typedef struct node//�߱��� 
{
	int adjvex;//�ڽӵ�
	struct node * next; 
}edgenode;
typedef struct vnode//ͷ��� 
{
	char vertex;	//������Ϣ 
	edgenode *firstedge;//�ڽӱ��ͷָ�� 
 } vertexnode;
 typedef struct//�ڽӱ����� 
 {
 	vertexnode adjlist[M];//���ͷ����˳��� 
 	int n,e;				//ͼ�Ķ����������
	  
  } linkedgraph;
  int visited[M];
  
  void creatwithfile(linkedgraph *g,char *filename,int c )//c=0��ʾ��������ͼ
  {
  	int i,j,k;
  	edgenode*s;
  	FILE *fp;
  	fp = fopen(filename,"r");
  	if(fp)
  	{
  		fscanf(fp,"%d%d",&g->n,&g->e);
  		for(i = 0;i<g->n;i++)
  		{fscanf(fp,"%d",&g->adjlist[i].vertex);//���붥����Ϣ
			g->adjlist[i].firstedge = NULL;		//�߱���Ϊ�� 
			 
		  }
		for(k=0;k<g->e;k++)//ѭ��e�ν����߱�
		{
			fscanf(fp,"%d%d",&i,&j);//������������(i,j) 
			s = (edgenode*)malloc(sizeof(edgenode));
			s->adjvex = j;//�ڽӵ����Ϊj 
			s->next = g->adjlist[i].firstedge;
			g->adjlist[i].firstedge = s; //���½ڵ�*s���붥��vi�ı߱�ͷ��
			if(c=0)
			{
				s = (edgenode*)malloc(sizeof(edgenode));
				s->adjvex = i;//�ڽӵ����Ϊi
				s->next = g->adjlist[j].firstedge;
				g->adjlist[j].firstedge = s; //���½ڵ�*s���붥��vj�ı߱�ͷ��
			 } 
		 }
		 fclose(fp); 
	
	  }
	else
	  	g->n = 0;//���ļ�ʧ�� 
  	
   } 
   
   linkedgraph *create(int c)//c=0��ʾ��������ͼ
   {
   	linkedgraph*g;
   	g = (linkedgraph*)malloc(sizeof(linkedgraph));
   	int i,j,k;
   	edgenode *s;
   	printf("���������ͱ���: \n");
   	scanf("%d%d",&g->n,&g->e);//���붥�����ͱ���
	printf("������ֵ��\n");
	getchar();
	for(i=0;i<g->n;i++)
	{
		scanf("%c",&g->adjlist[i].vertex);
		getchar();
		g->adjlist[i].firstedge = NULL;//�߱��ÿ� 
	 } 
	 if(c == 0) printf("�����������ԣ�\n");
	 else printf("�����������ԣ�\n");
	 for(k=0;k<g->e;k++)//ѭ��e�ν��� 
	 {
			scanf("%d%d",&i,&j);//������������(i,j) 
			s = (edgenode*)malloc(sizeof(edgenode));
			s->adjvex = j;//�ڽӵ����ζj 
			s->next = g->adjlist[i].firstedge;
			g->adjlist[i].firstedge = s; //���½ڵ�*s���붥��vi�ı߱�ͷ��
			if(c == 0)
			{
			s = (edgenode*)malloc(sizeof(edgenode));
			s->adjvex = i;//�ڽӵ����ζi 
			s->next = g->adjlist[j].firstedge;
			g->adjlist[j].firstedge = s; //���½ڵ�*s���붥��vi�ı߱�ͷ��
			 } 
	  } 
	  return g;
	} 
 	void dfs(linkedgraph*g,int i)
 	{
 		edgenode*p;
 		printf("visit vertex: %c \n",g->adjlist[i].vertex);//���ʶ���i
		visited[i] = 1;
		p = g->adjlist[i].firstedge;
		while(p)
		{
			if(visited[p->adjvex])
				dfs(g,p->adjvex);
			p=p->next;
		 } 
	 }
	 void dfstraverse(linkedgraph*g)
	 {
	 	int i;
	 	for(i=0;i<g->n;i++)
	 		visited[i] = 0;
	 	for(i=0;i<g->n;i++)
	 		if(!visited[i])
	 			dfs(g,i);
	 }
	 void bfs(linkedgraph *g,int i)
	 {
	 	int j;
	 	edgenode*p;
	 	int queue[M],front,rear;//����һ������
		front = rear = 0;		//��ʼ���ն���
		printf("%c",g->adjlist[i].vertex);//���ʸ��ڵ�
		visited[i] = 1;
		queue[rear++] = i;//�����ʽ�����
		while(rear>front)
		{
			j = queue[front++];//����
			p = g->adjlist[j].firstedge;
			while(p)
			{
				if(visited[p->adjvex] == 0)
				{
					printf("%c",g->adjlist[p->adjvex].vertex);
					queue[rear++] = p->adjvex;
					visited[p->adjvex] = 1;
				}
				p = p->next;
			 } 
		 } 
	 	
	 }
	 int bfstraverse(linkedgraph *g)
{
    int i, count = 0;
    for (i = 0; i < g->n; i++)
        visited[i] = 0;
    for (i = 0; i < g->n; i++)
        if (!visited[i]) //viδ�����ʹ�
        {
            printf("\n");
            count++;
            bfs(g, i);
        }
    return count;
}

int main()
{
    linkedgraph *h;
    h = create(0);
    printf("��ȱ�����\n");
    dfstraverse(h);
    printf("��ȱ�����\n");
    int count = bfstraverse(h);
    printf("\n��ͼ����ͨ����Ϊ��\n");
    printf("%d\n", count);
    return 0;
}
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
