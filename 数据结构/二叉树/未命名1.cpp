#inlcude<algorithm>
#include<string.h>
#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
#include<map>
#include<set>
#define MAXSIZE 20
******˳��洢****** 
typedef char datatype; //���ֵ������ 
//һ�������˳��洢���ݽṹ�Ķ������£� 
typedef struct
{
	datatype data;
	int lchild,rchild;
} node;					//�������������� 
typedef struct
{
	node tree[MAXSIZE];
	int n;				//����ʵ���������ĸ��� 
	int root;			//��Ÿ��ڵ���±� 
}tree;
//��˫��ָʾ�Ķ�����˳��洢���ݽṹ�Ķ������£�
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
 
 ******��ʽ�洢*******
 //�������� 
//ÿ�������������һ������������ָ��������ָ��lchild��rchild�ֱ�ָ�������Ӻ��Һ��ӽ��
typedef char datatype;
typedef struct node
{
	datatype data;
	struct node *lchild,*rchild;
 } bintnode,*bintree;
 bintree root;
 //��������
 //ÿ������ĸ��� ��lchild,rchild,data�Ͷ���������ͬ��parent��Ϊָ��˫�׽���ָ��
 //���ִ洢�ṹ���ڲ��Һ��ӽ���˫�׽�㣬���������˿ռ为��
typedef char datatype;
typedef struct node
{
	datatype data;
	struct node *lchild,*rchild,*parent;
 } bintnode,*bintree;
 bintree root;
 ******�������ı���****** 
  /*
  NLRǰ������ֳ��ȸ�����
  LNR��������ֳ��и�����
  LRN��������ֳƺ������ 
 */ 
 /*
 ǰ������ĵݹ����Ϊ ��
 ��������Ϊ��
 ��������
 ����
 ���ʸ��ڵ�
 ǰ�����������
 ǰ����������� 
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
 ��������ĵݹ����Ϊ��
 ��������Ϊ�� 
 ��������
 ����
 �������������
 ���ʸ��ڵ�
 ������������� 
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
 ��������ĵݹ����Ϊ��
 ��������Ϊ��
 ��������
 ����
 �������������
 �������������
 ���ʸ��ڵ� 
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
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
