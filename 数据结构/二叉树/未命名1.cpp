#inlcude<algorithm>
#include<string.h>
#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
#include<map>
#include<set>
#define MAXSIZE 20
******顺序存储****** 
typedef char datatype; //结点值的类型 
//一般二叉树顺序存储数据结构的定义如下： 
typedef struct
{
	datatype data;
	int lchild,rchild;
} node;					//二叉树结点的类型 
typedef struct
{
	node tree[MAXSIZE];
	int n;				//树中实际所含结点的个数 
	int root;			//存放根节点的下标 
}tree;
//带双亲指示的二叉树顺序存储数据结构的定义如下：
typedef struct 
{
	datatype data;
	int lchild,rchild;
	int parent;
 } node;
 typedef struct
 {
 	node tree [MAXSIZE];
 	int n;
 	int root;
 }tree;
 
 ******链式存储*******
 //二叉链表 
//每个结点有三个域，一个数据域两个指针域，两个指针lchild和rchild分别指向其左孩子和右孩子结点
typedef char datatype;
typedef struct node
{
	datatype data;
	struct node *lchild,*rchild;
 } bintnode,*bintree;
 bintree root;
 //三叉链表
 //每个结点四个域 ，lchild,rchild,data和二叉链表相同，parent域为指向双亲结点的指针
 //这种存储结构便于查找孩子结点和双亲结点，但是增加了空间负担
typedef char datatype;
typedef struct node
{
	datatype data;
	struct node *lchild,*rchild,*parent;
 } bintnode,*bintree;
 bintree root;
 ******二叉树的遍历****** 
  /*
  NLR前序遍历又称先根遍历
  LNR中序遍历又称中根遍历
  LRN后序遍历又称后根遍历 
 */ 
 /*
 前序遍历的递归过程为 ：
 若二叉树为空
 遍历结束
 否则
 访问根节点
 前序遍历左子树
 前序遍历右子树 
 */ 
 void preorder(bintree t) 
 {
 	if(t)
 	{
 		printf(t->data);
 		preorder(t->lchild);
 		preorder(t->rchild);
	 }
 }
 /*
 中序遍历的递归过程为：
 若二叉树为空 
 遍历结束
 否则
 中序遍历左子树
 访问根节点
 中序遍历右子树 
 */
 void inorder(bintree t)
 {
 	if(t)
 	{
 		inorder(t->lchild);
 		inorder(t->data);
 		inorder(t->rchild);
	 }
  } 
 /*
 后序遍历的递归过程为：
 若二叉树为空
 遍历结束
 否则
 后序遍历左子树
 后序遍历右子树
 访问根节点 
 */
 void postorder(bintree t)
 {
 	if(t)
 	{
 		postorder(t->lchild);
 		postorder(t->rchild);
 		postorder(t->data);
 		
	 }
  } 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
