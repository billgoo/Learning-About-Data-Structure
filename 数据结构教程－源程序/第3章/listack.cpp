#include <stdio.h>
#include <malloc.h>
typedef char ElemType;
typedef struct linknode
{	
	ElemType data;				//������
	struct linknode *next;		//ָ����
} LiStack;						//��ջ���Ͷ���
void InitStack(LiStack *&s)
{
	s=(LiStack *)malloc(sizeof(LiStack));
	s->next=NULL;
}
void DestroyQueue(LiStack *&s)
{
	LiStack *p=s->next;
	while (p!=NULL)
	{	
		free(s);
		s=p;
		p=p->next;
	}
	free(s);	//sָ��β���,�ͷ���ռ�
}
int StackLength(LiStack *s)
{
	int i=0;
	LiStack *p;
	p=s->next;
	while (p!=NULL)
	{	
		i++;
		p=p->next;
	}
	return(i);
}
bool StackEmpty(LiStack *s)
{
	return(s->next==NULL);
}
void Push(LiStack *&s,ElemType e)
{	LiStack *p;
	p=(LiStack *)malloc(sizeof(LiStack));
	p->data=e;				//�½�Ԫ��e��Ӧ�Ľڵ�*p
	p->next=s->next;		//����*p�ڵ���Ϊ��ʼ�ڵ�
	s->next=p;
}
bool Pop(LiStack *&s,ElemType &e)
{	LiStack *p;
	if (s->next==NULL)		//ջ�յ����
		return false;
	p=s->next;				//pָ��ʼ�ڵ�
	e=p->data;
	s->next=p->next;		//ɾ��*p�ڵ�
	free(p);				//�ͷ�*p�ڵ�
	return true;
}
bool GetTop(LiStack *s,ElemType &e)
{	if (s->next==NULL)		//ջ�յ����
		return false;
	e=s->next->data;
	return true;
}
