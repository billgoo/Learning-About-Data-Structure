#include "dlinklist.cpp"
void sort(DLinkList *&L)	//˫����ڵ�����
{	
	DLinkList *p,*pre,*q;
	p=L->next->next;		//pָ��L�ĵ�2�����ݽڵ�
	L->next->next=NULL;		//����ֻ��һ�����ݽڵ�������
	while (p!=NULL)
	{	q=p->next;			//q����*p�ڵ��̽ڵ��ָ��
		pre=L;				//�������ͷ���бȽ�,preָ�����*p��ǰ���ڵ�
		while (pre->next!=NULL && pre->next->data<p->data)
			pre=pre->next;	//����������Ҳ���*p��ǰ���ڵ�*pre
		p->next=pre->next;	//��*pre֮����뵽*p�ڵ�
		if (pre->next!=NULL)
			pre->next->prior=p;
		pre->next=p;
		p->prior=pre;
		p=q;				//ɨ��ԭ˫�������µĽڵ�
	}
}

void main()
{
	ElemType a[]={1,8,0,4,9,7,5,2,3,6};
	DLinkList *L;
	CreateListR(L,a,10);
	printf("L:");DispList(L);
	printf("����\n");
	sort(L);
	printf("L:");DispList(L);
	DestroyList(L);
}
