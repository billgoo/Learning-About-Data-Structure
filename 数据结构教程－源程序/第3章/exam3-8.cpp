#include <stdio.h>
#include <malloc.h>
typedef int ElemType;
typedef struct node
{
	ElemType data;
	struct node *next;
} LinkList;
void initQueue(LinkList *&rear)				//��ʼ���������㷨
{
	rear=NULL;
}
void enQueue(LinkList *&rear,ElemType x)	//���������㷨
{	
	LinkList *p;
	p=(LinkList *)malloc(sizeof(LinkList));	//�����½ڵ�
	p->data=x;
	if (rear==NULL)						//ԭ����Ϊ��
	{
		p->next=p;						//����ѭ������
		rear=p;
	}
	else
	{
		p->next=rear->next;				//��*p�ڵ���뵽*rear�ڵ�֮��
		rear->next=p;
		rear=p;							//��rearָ������²���Ľڵ�
	}
}
bool deQueue(LinkList *&rear,ElemType &x)		//���������㷨
{
	LinkList *q;
	if (rear==NULL)						//�ӿ�
		return false;
	else if (rear->next==rear)			//ԭ����ֻ��һ���ڵ�
	{
		x=rear->data;
		free(rear);
		rear=NULL;
	}
	else									//ԭ���������������ϵĽڵ�
	{	
		q=rear->next;
		x=q->data;
		rear->next=q->next;
		free(q);
	}
	return true;
}
bool queueEmpty(LinkList *rear)				//�жӿ������㷨
{
	return(rear==NULL);
}

void main()
{
	LinkList *q;
	ElemType e;
	initQueue(q);
	enQueue(q,1);
	enQueue(q,2);
	enQueue(q,3);
	enQueue(q,4); 
	printf("����˳��:");
	while (!queueEmpty(q))
	{
		deQueue(q,e);
		printf("%d ",e);
	}
	printf("\n"); 
}
