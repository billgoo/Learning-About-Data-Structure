#include <stdio.h>
#include <malloc.h>
typedef int ElemType;
typedef struct LNode  		//���嵥����������
{
	ElemType data;
	struct LNode *next;		//ָ���̽��
} LinkList;
void CreateListF(LinkList *&L,ElemType a[],int n)
//ͷ�巨����������
{
	LinkList *s;int i;
	L=(LinkList *)malloc(sizeof(LinkList));  	//����ͷ���
	L->next=NULL;
	for (i=0;i<n;i++)
	{	
		s=(LinkList *)malloc(sizeof(LinkList));//�����½��
		s->data=a[i];
		s->next=L->next;			//��*s����ԭ��ʼ���֮ǰ,ͷ���֮��
		L->next=s;
	}
}
void CreateListR(LinkList *&L,ElemType a[],int n)
//β�巨����������
{
	LinkList *s,*r;int i;
	L=(LinkList *)malloc(sizeof(LinkList));  	//����ͷ���
	L->next=NULL;
	r=L;					//rʼ��ָ���ն˽��,��ʼʱָ��ͷ���
	for (i=0;i<n;i++)
	{	
		s=(LinkList *)malloc(sizeof(LinkList));//�����½��
		s->data=a[i];
		r->next=s;			//��*s����*r֮��
		r=s;
	}
	r->next=NULL;			//�ն˽��next����ΪNULL
}
void InitList(LinkList *&L)
{
	L=(LinkList *)malloc(sizeof(LinkList));  	//����ͷ���
	L->next=NULL;
}
void DestroyList(LinkList *&L)
{
	LinkList *p=L,*q=p->next;
	while (q!=NULL)
	{	free(p);
		p=q;
		q=p->next;
	}
	free(p);	//��ʱqΪNULL,pָ��β���,�ͷ���
}
bool ListEmpty(LinkList *L)
{
	return(L->next==NULL);
}
int ListLength(LinkList *L)
{
	LinkList *p=L;int i=0;
	while (p->next!=NULL)
	{	i++;
		p=p->next;
	}
	return(i);
}
void DispList(LinkList *L)
{
	LinkList *p=L->next;
	while (p!=NULL)
	{	printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}
bool GetElem(LinkList *L,int i,ElemType &e)
{
	int j=0;
	LinkList *p=L;
	while (j<i && p!=NULL)
	{	j++;
		p=p->next;
	}
	if (p==NULL)			//�����ڵ�i�����ݽ��
		return false;
	else					//���ڵ�i�����ݽ��
	{	e=p->data;
		return true;
	}
}
int LocateElem(LinkList *L,ElemType e)
{
	LinkList *p=L->next;
	int n=1;
	while (p!=NULL && p->data!=e)
	{	p=p->next;
		n++;
	}
	if (p==NULL)
		return(0);
	else
		return(n);
}
bool ListInsert(LinkList *&L,int i,ElemType e)
{
	int j=0;
	LinkList *p=L,*s;
	while (j<i-1 && p!=NULL) //���ҵ�i-1�����
	{	j++;
		p=p->next;
	}
	if (p==NULL)	//δ�ҵ�λ��Ϊi-1�Ľ��
		return false;
	else			//�ҵ�λ��Ϊi-1�Ľ��*p
	{	s=(LinkList *)malloc(sizeof(LinkList));//�����½��*s
		s->data=e;
		s->next=p->next;						//��*s���뵽*p֮��
		p->next=s;
		return true;
	}
}
bool ListDelete(LinkList *&L,int i,ElemType &e)
{
	int j=0;
	LinkList *p=L,*q;
	while (j<i-1 && p!=NULL)	//���ҵ�i-1�����
	{	j++;
		p=p->next;
	}
	if (p==NULL)				//δ�ҵ�λ��Ϊi-1�Ľ��
		return false;
	else						//�ҵ�λ��Ϊi-1�Ľ��*p
	{	q=p->next;				//qָ��Ҫɾ���Ľ��
		if (q==NULL) 
			return false;			//�������ڵ�i�����,����false
		e=q->data;
		p->next=q->next;		//�ӵ�������ɾ��*q���
		free(q);				//�ͷ�*q���
		return true;
	}
}
