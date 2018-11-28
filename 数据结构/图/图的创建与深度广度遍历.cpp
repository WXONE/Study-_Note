#include<stdio.h>
#include<stdlib.h>
#define Max 10086

int visited[Max];

typedef struct node {
	int adjvex;                   //�ڽӵ㣻
	struct node *next;
}EdgeNode;

typedef struct vnode {
	char vertex;                  //������Ϣ
	EdgeNode *FirstEdge;          //����ͷָ��
}VertexNode;

typedef struct {
	VertexNode adjlist[Max];         //��ͷ�ڵ�
	int n;                           //����
	int e;                           //����
}LinkedGraph;

typedef struct edgedata          //Prim��С������;
{
	int beg;
	int en;
	int length;
}edge;

void create(LinkedGraph *g, char *filename, int c)
{
	int i, j, k;
	EdgeNode *s;
	FILE *fp;
	fp = fopen(filename, "r");
	if (fp)
	{
		fscanf(fp, "%d%d", &g->n, &g->e);            //���붥�������������

		for (i = 0; i < g->n; i++)                  // ���붥����Ϣ��
		{
			fscanf(fp, "%ls", &g->adjlist[i].vertex);
			g->adjlist[i].FirstEdge = NULL;
		}

		for (k = 0; k < g->e; k++)                     //����ߵ���Ϣ
		{
			fscanf(fp, "%d%d", &i, &j);
			s = (EdgeNode *)malloc(sizeof(EdgeNode));          //���ٿռ䣻
			s->adjvex = j;
			s->next = g->adjlist[i].FirstEdge;
			g->adjlist[i].FirstEdge = s;
			if (c == 0)                  //����ͼ���ظ���·��
			{
				s = (EdgeNode *)malloc(sizeof(EdgeNode));
				s->adjvex = i;
				s->next = g->adjlist[j].FirstEdge;
				g->adjlist[j].FirstEdge = s;
			}
		}

		fclose(fp);
	}
	else
		g->n = 0;
}
void print(LinkedGraph g)
{
	printf("������");
}
void dfs(LinkedGraph g, int i)              //dfs
{
	EdgeNode *p;
	printf("���ʶ��㣺%c\n", g.adjlist[i].vertex);
	visited[i] = 1;
	p = g.adjlist[i].FirstEdge;
	while (p)
	{
		if (!visited[p->adjvex])
			dfs(g, p->adjvex);
		p = p->next;
	}
}

void DFSTraverse(LinkedGraph g)          //dfs����ͼ��
{
	int i;
	for (i = 0; i < g.n; i++)
		visited[i] = 0;
	for (i = 0; i < g.n; i++)
		if (!visited[i])
			dfs(g, i);
}

void bfs(LinkedGraph g, int i)             //bfs
{
	int j;
	EdgeNode *p;
	int queue[Max], front, rear;
	front = rear = 0;
	printf("%c ", g.adjlist[i].vertex);
	visited[i] = 1;
	queue[rear++] = i;
	while (rear > front)
	{
		j = queue[front++];
		p = g.adjlist[j].FirstEdge;
		while (p)
		{
			if (visited[p->adjvex] == 0)
			{
				printf("%c ", g.adjlist[p->adjvex].vertex);
				queue[rear++] = p->adjvex;
				visited[p->adjvex] = 1;
			}
			p = p->next;
		}
	}
}

int BFSTraverse(LinkedGraph g)
{
	int i, count = 0;
	for (i = 0; i < g.n; i++)
		visited[i] = 0;
	for (i = 0; i < g.n; i++)
	{
		if (!visited[i])
		{
			printf("\n");
			count++;
			bfs(g, i);
		}
	}
	return count;
}

int main()
{
	LinkedGraph g;
	int count;
	create(&g, "1.txt", 0);
	printf("\n ���ͼ�������ӵģ�\n");
	print(g);
	count = BFSTraverse(g);
	printf("������%d����ͨ���� \n", count);
	return 0;
}
