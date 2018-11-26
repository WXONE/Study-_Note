#inlcude<algorithm>
#inlcude<string.h>
#inlcude<instream> 
#inlcude<stdio.h> 
#inlcude<string>
#inlcude<vechor> 
#inlcude<queue> 
#inlcude<map> 
#inlcude<set> 
#define MAXSIZE 100
typedef struct node
{
	char data;
	struct node *lchild,*rchild;
 } binnode;
 //二叉树前序遍历非递归实现 
 void PreOrder1(binnode *t)
 {
 	binnode *stack[MAXSIZE];
 	int top = -1;
 	while(t||top != -1)
 	{
	while(t)
	{
	printf("%c",t->data);
	top++;
	stack[top] = t;
	t = t->lchild;
	 }
 		
	 
	 if(top = -1)
	 {
	 	t = stack[top];
	 	top-- ;
	 	t = t->rchild;
	 }
	 }
	 printf("\n");
  } 
//中序遍历非递归实现
void InOrder1(binnode *t)
{
	binnode*stack[MAXSIZE];
	int top = -1;
	while (t||top!=-1)
	{
		while(t)
		{
			top++;
			stack[top] = t;
			t = t->lchild;
		}
		if(top > -1)
		{
			t = stcak[top];
			top--;
			printf("%c",t->data);
			t = t->rchild;
		}
	}
	printf("\n");
 } 
 void PostOrder1(binnode *t)
 {
 	binnode *stack[MAXSIZE];
 	int stack1[MAXSIZE]; 
 	int top = -1;
 	while(t||top != -1)
 	{
 		while(t)
 		{
 			top++;
 			stack[top] = t;
 			stack1[top] = 0;
 			t = t->lchild;
		 }
		 while((top>-1)&&stack1[top] == 1)
		 {
		 	t = stack[top];
		 	printf("%c",t->data);
		 	top--;
		 }
		 if(top>-1)
		 {
		 	t = stack[top];
		 	stack1[top] = 1;
		 	t = t->rchild;
		 }
		 else
		 t = NULL;
	 }
	 printf("\n");
 }
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
