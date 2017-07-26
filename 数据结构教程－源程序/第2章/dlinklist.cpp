#include <stdio.h>
#include <malloc.h>
typedef int ElemType;
typedef struct DNode		//����˫����������
{
	ElemType data;
	struct DNode *prior;	//ָ��ǰ�����
	struct DNode *next;		//ָ���̽��
} DLinkList;
void CreateListF(DLinkList *&L,ElemType a[],int n)
//ͷ�巨��˫����
{
	DLinkList *s;int i;
	L=(DLinkList *)malloc(sizeof(DLinkList));  	//����ͷ���
	L->prior=L->next=NULL;
	for (i=0;i<n;i++)
	{	
		s=(DLinkList *)malloc(sizeof(DLinkList));//�����½��
		s->data=a[i];
		s->next=L->next;			//��*s����ԭ��ʼ���֮ǰ,ͷ���֮��
		if (L->next!=NULL) L->next->prior=s;
		L->next=s;s->prior=L;
	}
}
void CreateListR(DLinkList *&L,ElemType a[],int n)
//β�巨��˫����
{
	DLinkList *s,*r;int i;
	L=(DLinkList *)malloc(sizeof(DLinkList));  	//����ͷ���
	L->prior=L->next=NULL;
	r=L;					//rʼ��ָ���ն˽��,��ʼʱָ��ͷ���
	for (i=0;i<n;i++)
	{	
		s=(DLinkList *)malloc(sizeof(DLinkList));//�����½��
		s->data=a[i];
		r->next=s;s->prior=r;	//��*s����*r֮��
		r=s;
	}
	r->next=NULL;			//�ն˽��next����ΪNULL
}
void InitList(DLinkList *&L)
{
	L=(DLinkList *)malloc(sizeof(DLinkList));  	//����ͷ���
	L->prior=L->next=NULL;
}
void DestroyList(DLinkList *&L)
{
	DLinkList *p=L,*q=p->next;
	while (q!=NULL)
	{
		free(p);
		p=q;
		q=p->next;
	}
	free(p);
}
bool ListEmpty(DLinkList *L)
{
	return(L->next==NULL);
}
int ListLength(DLinkList *L)
{
	DLinkList *p=L;
	int i=0;
	while (p->next!=NULL)
	{
		i++;
		p=p->next;
	}
	return(i);
}
void DispList(DLinkList *L)
{
	DLinkList *p=L->next;
	while (p!=NULL)
	{
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}
bool GetElem(DLinkList *L,int i,ElemType &e)
{
	int j=0;
	DLinkList *p=L;
	while (j<i && p!=NULL)
	{
		j++;
		p=p->next;
	}
	if (p==NULL)
		return false;
	else
	{
		e=p->data;
		return true;
	}
}
int LocateElem(DLinkList *L,ElemType e)
{
	int n=1;
	DLinkList *p=L->next;
	while (p!=NULL && p->data!=e)
	{
		n++;
		p=p->next;
	}
	if (p==NULL)
		return(0);
	else
		return(n);
}
bool ListInsert(DLinkList *&L,int i,ElemType e)
{
	int j=0;
	DLinkList *p=L,*s;
	while (j<i-1 && p!=NULL)
	{
		j++;
		p=p->next;
	}
	if (p==NULL)	//δ�ҵ���i-1�����
		return false;
	else			//�ҵ���i-1�����*p
	{
		s=(DLinkList *)malloc(sizeof(DLinkList));	//�����½��*s
		s->data=e;	
		s->next=p->next;		//��*s���뵽*p֮��
		if (p->next!=NULL) p->next->prior=s;
		s->prior=p;
		p->next=s;
		return true;
	}
}
bool ListDelete(DLinkList *&L,int i,ElemType &e)
{
	int j=0;
	DLinkList *p=L,*q;
	while (j<i-1 && p!=NULL)
	{
		j++;
		p=p->next;
	}
	if (p==NULL)				//δ�ҵ���i-1�����
		return false;
	else						//�ҵ���i-1�����*p
	{
		q=p->next;				//qָ��Ҫɾ���Ľ��
		if (q==NULL) 
			return false;		//�����ڵ�i�����
		e=q->data;
		p->next=q->next;		//�ӵ�������ɾ��*q���
		if (p->next!=NULL) p->next->prior=p;
		free(q);				//�ͷ�*q���
		return true;
	}
}
