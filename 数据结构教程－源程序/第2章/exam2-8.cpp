#include "dlinklist.cpp"
void reverse(DLinkList *&L)		//˫����ڵ�����
{
	DLinkList *p=L->next,*q;	//pָ�򿪺ýڵ�
	L->next=NULL;				//����ֻ��ͷ�ڵ��˫����L
	while (p!=NULL)				//ɨ��L�����ݽڵ�
	{	q=p->next;				//��ͷ�巨���޸�*p��next��,��q�������̽ڵ�
		p->next=L->next;		//����ͷ�巨��*p�ڵ���뵽˫������
		if (L->next!=NULL)		//��L�д������ݽڵ�,�޸���ǰ��ָ��
			L->next->prior=p;
		L->next=p;
		p->prior=L;
		p=q;					//��p����ָ�����̽ڵ�
	}
}
void main()
{
	ElemType a[]={1,8,0,4,9,7,5,2,3,6};
	DLinkList *L;
	CreateListR(L,a,10);
	printf("L:");DispList(L);
	printf("����\n");
	reverse(L);
	printf("L:");DispList(L);
	DestroyList(L);
}
