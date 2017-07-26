//ѭ��������������㺯��
#include <stdio.h>
#include <malloc.h>
typedef int ElemType;
typedef struct LNode		//���嵥����������
{
	ElemType data;
    struct LNode *next;
} LinkList;
void CreateListF(LinkList *&L,ElemType a[],int n)
//ͷ�巨����ѭ��������
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
	s=L->next;	
	while (s->next!=NULL)			//����β���,��sָ����
		s=s->next;
	s->next=L;						//β���next��ָ��ͷ���

}
void CreateListR(LinkList *&L,ElemType a[],int n)
//β�巨����ѭ��������
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
	r->next=L;				//β���next��ָ��ͷ���
}
void InitList(LinkList *&L)
{
	L=(LinkList *)malloc(sizeof(LinkList));	//����ͷ���
	L->next=L;
}
void DestroyList(LinkList *&L)
{
	LinkList *p=L,*q=p->next;
	while (q!=L)
	{
		free(p);
		p=q;
		q=p->next;
	}
	free(p);
}
bool ListEmpty(LinkList *L)
{
	return(L->next==L);
}
int ListLength(LinkList *L)
{
	LinkList *p=L;int i=0;
	while (p->next!=L)
	{
		i++;
		p=p->next;
	}
	return(i);
}
void DispList(LinkList *L)
{
	LinkList *p=L->next;
	while (p!=L)
	{
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}
bool GetElem(LinkList *L,int i,ElemType &e)
{
	int j=0;
	LinkList *p;
	if (L->next!=L)		//������Ϊ�ձ�ʱ
	{
		if (i==1)
		{
			e=L->next->data;
			return true;
		}
		else			//i��Ϊ1ʱ
		{
			p=L->next;
			while (j<i-1 && p!=L)
			{
				j++;
				p=p->next;
			}
			if (p==L)
				return false;
			else
			{
				e=p->data;
				return true;
			}
		}
	}
	else				//������Ϊ�ձ�ʱ
		return false;
}
int LocateElem(LinkList *L,ElemType e)
{
	LinkList *p=L->next;
	int n=1;
	while (p!=L && p->data!=e)
	{
		p=p->next;
		n++;
	}
	if (p==L)
		return(0);
	else
		return(n);
}
bool ListInsert(LinkList *&L,int i,ElemType e)
{
	int j=0;
	LinkList *p=L,*s;
	if (p->next==L || i==1)		//ԭ������Ϊ�ձ��i==1ʱ
	{
		s=(LinkList *)malloc(sizeof(LinkList));	//�����½��*s
		s->data=e;								
		s->next=p->next;		//��*s���뵽*p֮��
		p->next=s;
		return true;
	}
	else
	{
		p=L->next;
		while (j<i-2 && p!=L)
		{
			j++;
			p=p->next;
		}
		if (p==L)				//δ�ҵ���i-1�����
			return false;
		else					//�ҵ���i-1�����*p
		{
			s=(LinkList *)malloc(sizeof(LinkList));	//�����½��*s
			s->data=e;								
			s->next=p->next;						//��*s���뵽*p֮��
			p->next=s;
			return true;
		}
	}
}
bool ListDelete(LinkList *&L,int i,ElemType &e)
{
	int j=0;
	LinkList *p=L,*q;
	if (p->next!=L)					//ԭ������Ϊ�ձ�ʱ
	{
		if (i==1)					//i==1ʱ
		{
			q=L->next;				//ɾ����1�����
			e=q->data;
			L->next=q->next;
			free(q);
			return true;
		}
		else						//i��Ϊ1ʱ
		{
			p=L->next;
			while (j<i-2 && p!=L)
			{
				j++;
				p=p->next;
			}
			if (p==L)				//δ�ҵ���i-1�����
				return false;
			else					//�ҵ���i-1�����*p
			{
				q=p->next;			//qָ��Ҫɾ���Ľ��
				e=q->data;
				p->next=q->next;	//�ӵ�������ɾ��*q���
				free(q);			//�ͷ�*q���
				return true;
			}
		}
	}
	else return 0;
}
