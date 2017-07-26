#include <stdio.h>
#include <malloc.h>
#define MaxSize 100
typedef char ElemType;
typedef struct node 
{
	ElemType data;
	int ltag,rtag;      //���ӵ��������
	struct node *lchild;
	struct node *rchild;
} TBTNode;
void CreateTBTNode(TBTNode * &b,char *str)
{
	TBTNode *St[MaxSize],*p=NULL;
	int top=-1,k,j=0;  
	char ch;
	b=NULL;				//�����Ķ�������ʼʱΪ��
	ch=str[j];
	while (ch!='\0')	//strδɨ����ʱѭ��
	{
   	   	switch(ch) 
		{
		case '(':top++;St[top]=p;k=1; break;		//Ϊ����
		case ')':top--;break;
		case ',':k=2; break;                      	//Ϊ�ҽ��
		default:p=(TBTNode *)malloc(sizeof(TBTNode));
				p->data=ch;p->lchild=p->rchild=NULL;
		        if (b==NULL)					//*pΪ�������ĸ����
					b=p;
				else  							//�ѽ��������������
				{	
					switch(k) 
					{
					case 1:St[top]->lchild=p;break;
					case 2:St[top]->rchild=p;break;
					}
				}
		}
		j++;
		ch=str[j];
	}
}
void DispTBTNode(TBTNode *b) 
{
	if (b!=NULL)
	{
		printf("%c",b->data);
		if (b->lchild!=NULL || b->rchild!=NULL)
		{
			printf("(");
			DispTBTNode(b->lchild);
			if (b->rchild!=NULL) printf(",");
			DispTBTNode(b->rchild);
			printf(")");
		}
	}
}
TBTNode *pre;						//ȫ�ֱ���
void Thread(TBTNode *&p)
{
	if (p!=NULL)	
	{	
		Thread(p->lchild);    		//������������
		if (p->lchild==NULL)		//ǰ������
		{
			p->lchild=pre;        	//������ǰ����ǰ������
			p->ltag=1;
		}
		else p->ltag=0;
		if (pre->rchild==NULL)		//�������
		{	
			pre->rchild=p;     		//����ǰ�����ĺ������
		   	pre->rtag=1;
		}
		else pre->rtag=0;
	    pre=p;
	   	Thread(p->rchild);  		//������������
	}
}
TBTNode *CreaThread(TBTNode *b)     //����������������
{
	TBTNode *root;
	root=(TBTNode *)malloc(sizeof(TBTNode));  //���������
	root->ltag=0;root->rtag=1;
	root->rchild=b;
	if (b==NULL)                //�ն�����
		root->lchild=root;
	else
	{  	
		root->lchild=b;
		pre=root;             	//pre��*p��ǰ�����,����������
		Thread(b);   			//�������������������
		pre->rchild=root;    	//�����,����ָ�����������
		pre->rtag=1;
		root->rchild=pre;    	//�������������
	}
    return root;
}
void ThInOrder(TBTNode *tb)
{
	TBTNode *p=tb->lchild;		//ָ������
	while (p!=tb)		
	{
		while (p->ltag==0) p=p->lchild;
		printf("%c ",p->data);
		while (p->rtag==1 && p->rchild!=tb)
		{
			p=p->rchild;
			printf("%c ",p->data);
		}
		p=p->rchild;
	}
}
void main()
{
	TBTNode *b,*tb;
	CreateTBTNode(b,"A(B(D(,G)),C(E,F))");
	printf(" ������:");DispTBTNode(b);printf("\n");
	tb=CreaThread(b);
	printf(" ������������:");ThInOrder(tb);printf("\n");
}