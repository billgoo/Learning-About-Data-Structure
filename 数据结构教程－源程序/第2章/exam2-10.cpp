#include "clinklist.cpp"
int count(LinkList *L,ElemType x)
{
	int n=0;
	LinkList *p=L->next;	//ָ���1�����ݽ��
	while (p!=L)
	{	
		if (p->data==x) n++;
		p=p->next;
	}
	return(n);
}
void main()
{
	ElemType a[]={1,2,2,4,2,3,5,2,1,4};
	ElemType x=2;
	LinkList *L;
	CreateListR(L,a,10);
	printf("L:");DispList(L);
	printf("�ڵ�ֵΪ%d�Ľڵ����:%d\n",x,count(L,x));
	DestroyList(L);
}
