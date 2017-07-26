#include <stdio.h>
#include <malloc.h>
#define MaxSize 100
typedef char ElemType;
typedef struct node 
{	
	ElemType data;			//����Ԫ��
	struct node *lchild;	//ָ�����ӽ��
	struct node *rchild;	//ָ���Һ��ӽ��
} BTNode;
void CreateBTNode(BTNode * &b,char *str)
{
	BTNode *St[MaxSize],*p=NULL;
	int top=-1,k,j=0;  
	char ch;
	b=NULL;				//�����Ķ�������ʼʱΪ��
	ch=str[j];
	while (ch!='\0')  	//strδɨ����ʱѭ��
	{
   	   	switch(ch) 
		{
		case '(':top++;St[top]=p;k=1; break;		//Ϊ���ӽ��
		case ')':top--;break;
		case ',':k=2; break;                      		//Ϊ���ӽ���ҽ��
		default:p=(BTNode *)malloc(sizeof(BTNode));
				p->data=ch;p->lchild=p->rchild=NULL;
				if (b==NULL)                    	 	//*pΪ�������ĸ����
					b=p;
				else  								//�ѽ��������������
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
BTNode *FindNode(BTNode *b,ElemType x) 
{
	BTNode *p;
	if (b==NULL)
		return NULL;
	else if (b->data==x)
		return b;
	else  
	{
		p=FindNode(b->lchild,x);
		if (p!=NULL) 
			return p;
		else 
			return FindNode(b->rchild,x);
	}
}
BTNode *LchildNode(BTNode *p)
{
    return p->lchild;
}
BTNode *RchildNode(BTNode *p)
{
    return p->rchild;
}
int BTNodeHeight(BTNode *b) 
{
   	int lchildh,rchildh;
   	if (b==NULL) return(0); 				//�����ĸ߶�Ϊ0
   	else  
	{
		lchildh=BTNodeHeight(b->lchild);	//���������ĸ߶�Ϊlchildh
		rchildh=BTNodeHeight(b->rchild);	//���������ĸ߶�Ϊrchildh
		return (lchildh>rchildh)? (lchildh+1):(rchildh+1);
   	}
}
void DispBTNode(BTNode *b) 
{
	if (b!=NULL)
	{	printf("%c",b->data);
		if (b->lchild!=NULL || b->rchild!=NULL)
		{	printf("(");						//�к��ӽ��ʱ�����(
			DispBTNode(b->lchild);				//�ݹ鴦��������
			if (b->rchild!=NULL) printf(",");	//���Һ��ӽ��ʱ�����,
			DispBTNode(b->rchild);				//�ݹ鴦��������
			printf(")");						//�к��ӽ��ʱ�����)
		}
	}
}
/*������������������
void main()
{
	BTNode *b;
	CreateBTNode(b,"A(B(D,E),C(,F))");
	DispBTNode(b);
	printf("\n");
}
*/