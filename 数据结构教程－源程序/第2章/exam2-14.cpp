#include "linklist.cpp"
void dels(LinkList *&L)
{
	LinkList *p=L->next,*q;
	while (p->next!=NULL) 
	{
		if (p->data==p->next->data)		//�ҵ��ظ�ֵ�Ľڵ�
		{
			q=p->next;					//qָ������ظ�ֵ�Ľڵ�
			p->next=q->next;			//ɾ��*q�ڵ�
			free(q);
		}
		else							//�����ظ��ڵ�,pָ������
			p=p->next;
	}
}
void main()
{
	LinkList *L;
	ElemType a[]={1,2,2,2,3,3,3,3,3};
	CreateListR(L,a,9);
	printf("L:"); DispList(L);
	dels(L);
	printf("L:"); DispList(L);
	DestroyList(L);
}
