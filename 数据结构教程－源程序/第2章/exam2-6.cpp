#include "linklist.cpp"
void delmaxnode(LinkList *&L)
{
	LinkList *p=L->next,*pre=L,*maxp=p,*maxpre=pre;
	while (p!=NULL)					//��pɨ������������,preʼ��ָ����ǰ���ڵ�
	{
		if (maxp->data<p->data)		//���ҵ�һ������Ľڵ�
		{	maxp=p;					//����maxp
			maxpre=pre;				//����maxpre
		}
		pre=p;						//p��preͬ������һ���ڵ�
		p=p->next;
	}
	maxpre->next=maxp->next;		//ɾ��*maxp�ڵ�
	free(maxp);						//�ͷ�*maxp�ڵ�
}
void main()
{
	LinkList *L;
	int n=10;
	ElemType a[]={1,3,2,9,0,4,7,6,5,8};
	CreateListR(L,a,n);
	printf("L:");DispList(L);
	printf("ɾ�����ֵ�ڵ�\n");
	delmaxnode(L);
	printf("L:");DispList(L);
	DestroyList(L);
}