#include <stdio.h>
#include <malloc.h>
typedef int KeyType;
typedef char InfoType[10];
typedef struct node           		//��¼����
{
	KeyType key;              		//�ؼ�����
	InfoType data;             		//����������
	struct node *lchild,*rchild;	//���Һ���ָ��
} BSTNode;
int InsertBST(BSTNode *&p,KeyType k)	
{
   	if (p==NULL)						//ԭ��Ϊ��, �²���ļ�¼Ϊ�����
	{
		p=(BSTNode *)malloc(sizeof(BSTNode));
		p->key=k;
		p->lchild=p->rchild=NULL;
		return 1;
	}
	else if (k==p->key) 				//���д�����ͬ�ؼ��ֵĽ��,����0
		return 0;
	else if (k<p->key) 
		return InsertBST(p->lchild,k);	//���뵽*p����������
	else  
		return InsertBST(p->rchild,k);  //���뵽*p����������
}
BSTNode *CreateBST(KeyType A[],int n)	//����BST�������ָ��
{
	BSTNode *bt=NULL;         			//��ʼʱbtΪ����
	int i=0;
	while (i<n) 
	{
		InsertBST(bt,A[i]);  			//���ؼ���A[i]�������������T��
		i++;
    }
    return bt;               			//���ؽ����Ķ����������ĸ�ָ��
}
void DispBST(BSTNode *bt)		//���һ�����������
{
	if (bt!=NULL)
	{	printf("%d",bt->key);
		if (bt->lchild!=NULL || bt->rchild!=NULL)
		{	printf("(");						//�к��ӽ��ʱ�����(
			DispBST(bt->lchild);				//�ݹ鴦��������
			if (bt->rchild!=NULL) printf(",");	//���Һ��ӽ��ʱ�����,
			DispBST(bt->rchild);				//�ݹ鴦��������
			printf(")");						//�к��ӽ��ʱ�����)
		}
	}
}
KeyType maxnode(BSTNode *p) //����һ�ö����������е������
{
	while (p->rchild!=NULL)
		p=p->rchild;
	return(p->key);
}
KeyType minnode(BSTNode *p)	  //����һ�ö����������е���С���
{
	while (p->lchild!=NULL)
		p=p->lchild;
	return(p->key);
}
void maxminnode(BSTNode *p)
{
	if (p!=NULL)
	{	
		if (p->lchild!=NULL)
			printf("�������������Ϊ:%d\n",maxnode(p->lchild));
		if (p->rchild!=NULL)
			printf("����������С���Ϊ:%d\n",minnode(p->rchild));
	}
}
void main()
{
	BSTNode *bt;
	int n=12,x=46;
	KeyType a[]={25,18,46,2,53,39,32,4,74,67,60,11};
	bt=CreateBST(a,n);
	printf("BST:");DispBST(bt);printf("\n");
	maxminnode(bt);
}