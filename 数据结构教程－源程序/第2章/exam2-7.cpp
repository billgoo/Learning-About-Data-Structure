#include "linklist.cpp"
void sort(LinkList *&L)
{	LinkList *p,*pre,*q;
	p=L->next->next;		//pָ��L�ĵ�2�����ݽڵ�
	L->next->next=NULL;		//����ֻ��һ�����ݽڵ�������
	while (p!=NULL)
	{	q=p->next;			//q����*p�ڵ��̽ڵ��ָ��
		pre=L;				//�������ͷ���бȽ�,preָ�����*p��ǰ���ڵ�
		while (pre->next!=NULL && pre->next->data<p->data)
			pre=pre->next;	//����������Ҳ���*p��ǰ���ڵ�*pre
		p->next=pre->next;	//��*pre֮�����*p
		pre->next=p;
		p=q;				//ɨ��ԭ���������µĽڵ�
	}
}
void main()
{
	LinkList *L;
	int n=10;
	ElemType a[]={1,3,2,9,0,4,7,6,5,8};
	CreateListR(L,a,n);
	printf("L:");DispList(L);
	printf("����\n");
	sort(L);
	printf("L:");DispList(L);
	DestroyList(L);
}

