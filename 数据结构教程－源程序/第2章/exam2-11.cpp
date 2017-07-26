#include "cdlinklist.cpp"
bool delelem(DLinkList *&L,ElemType x)
{
	DLinkList *p=L->next; 
	while (p!=L && p->data!=x)
		p=p->next;
	if (p!=L)						//�ҵ���һ��Ԫ��ֵΪx�Ľڵ�
	{
		p->next->prior=p->prior;	//ɾ���ڵ�*p
		p->prior->next=p->next;
		free(p);
		return true;
	}
	else 
		return false;
}
void main()
{
	ElemType a[]={1,2,2,4,2,3,5,2,1,4};
	ElemType x=1;
	DLinkList *L;
	CreateListR(L,a,10);
	printf("L:");DispList(L);
	printf("ɾ����һ���ڵ�ֵΪ%d�Ľڵ�\n",x);
	if (delelem(L,x))
	{
		printf("L:");DispList(L);
	}
	else
		printf("ѭ��˫����L�в�����Ԫ��ֵΪ%d�Ľڵ�\n",x);
	DestroyList(L);
}
