#include"stdio.h"
#include"string.h"
#include"stdlib.h"
#define M 30 //Ԥ����ͼ����󶥵�
//��������
typedef struct node{
	//�߽�����Ͷ���
	int adjvex;
	struct node *next; 
}edgenode;
typedef struct de{
	//��������ȵ�ͷ��㶨��
	edgenode* FirstEdge;
	char vertex;
	int id;//��������� 
}vertexnode;
typedef struct{
	//AOV���ڽӱ�ṹ
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
			if(c == 0)//����ͼ
			{
				s = (edgenode*)malloc(sizeof*(edgenode));
				s->adjvex = j;
				s->next = g->adjlist[i].FirstEdge;
				g->adjlist[i].FirstEdge = s;
				
			 } 
		}
		fclose(fp);//�ر��ļ��� 
	}
	else
	{
		g->n = 0;
		printf("�ļ���ʧ��\n");
	 } 
 } 
 //���������㷨
 int TopSort(AovGraph g)
 {
 	int k = 0,i,j,v,flag[M];
 	int queue[M];//����
	int front,rear;
	edgenode *p;
	front = rear = 0;//��ʼ������
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
	printf("\n ��AOV��������˽ṹΪ��\n");
	while(front < rear)//�����ǰ���в�Ϊ�� 
	{
		v = queue[front++];//������Ԫ�س���
		printf("%c",g.adjlist[v].vertex);
		k++;//������+1
		p = g.adjlist[v].FirstEdge;
		while(p)//��������v�ڽӵĶ������-1
		{
			j = p->adjvex;
			if(--g.adjlist[j].id == 0 && flag[j] == 0);//������Ϊ0�򽫽���
			{
				queue[rear++] = j;
				flag[j] = 1;//���Ϊ�Ѿ����ʹ� 
			 } 
			p = p->next;
		 } 
	}
	return k;//��������Ľڵ���� 
  } 
int main()
{
	AovGraph g;
	char filename[20] = "D:\\Desktop\\Test.txt";
	createTop(&g, filename, 1);
	printf("��������Ľڵ������%d\n", TopSort(g));
	system("pause");
	return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
