#include<stdio.h>
#include<stdlib.h>
#define Max 10086

int visited[Max];

typedef struct node {
	int adjvex;                   //邻接点；
	struct node *next;
}EdgeNode;

typedef struct vnode {
	char vertex;                  //顶点信息
	EdgeNode *FirstEdge;          //链表头指针
}VertexNode;

typedef struct {
	VertexNode adjlist[Max];         //放头节点
	int n;                           //顶点
	int e;                           //边数
}LinkedGraph;

typedef struct edgedata          //Prim最小生成树;
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
		fscanf(fp, "%d%d", &g->n, &g->e);            //读入顶点数，与边数；

		for (i = 0; i < g->n; i++)                  // 读入顶点信息；
		{
			fscanf(fp, "%ls", &g->adjlist[i].vertex);
			g->adjlist[i].FirstEdge = NULL;
		}

		for (k = 0; k < g->e; k++)                     //读入边的信息
		{
			fscanf(fp, "%d%d", &i, &j);
			s = (EdgeNode *)malloc(sizeof(EdgeNode));          //开辟空间；
			s->adjvex = j;
			s->next = g->adjlist[i].FirstEdge;
			g->adjlist[i].FirstEdge = s;
			if (c == 0)                  //无向图；重复建路；
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
	printf("嘤嘤嘤");
}
void dfs(LinkedGraph g, int i)              //dfs
{
	EdgeNode *p;
	printf("访问顶点：%c\n", g.adjlist[i].vertex);
	visited[i] = 1;
	p = g.adjlist[i].FirstEdge;
	while (p)
	{
		if (!visited[p->adjvex])
			dfs(g, p->adjvex);
		p = p->next;
	}
}

void DFSTraverse(LinkedGraph g)          //dfs遍历图；
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
	printf("\n 这个图是这样子的：\n");
	print(g);
	count = BFSTraverse(g);
	printf("里面有%d个联通分量 \n", count);
	return 0;
}
