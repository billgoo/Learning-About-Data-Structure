#include "linklist.cpp"
void release(LinkList *L)
{
	if (L!=NULL)
	{
		release(L->next);
		free(L);
	}
}
void main()
{
	LinkList *h;
	int a[]={1,2,3,4};
	InitList(h);
	ListInsert(h,1,1);
	ListInsert(h,2,2);
	ListInsert(h,3,3);
	ListInsert(h,4,4);
	printf("������:");
	DispList(h);
	printf("�ͷŵ�����\n");
	release(h->next);
	free(h);		//�ͷ�ͷ�ڵ�
}
