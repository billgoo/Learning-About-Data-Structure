#include "sqlist.cpp"  
void move1(SqList *&L)
{
	int i=0,j=L->length-1;
	ElemType pivot=L->data[0];	//��data[0]Ϊ��׼
	ElemType tmp;
	while (i<j)  			//���������˽������м�ɨ��,ֱ��i=jΪֹ
	{	
		while (i<j && L->data[j]>pivot) 
			j--;  			//��������ɨ��,�ҵ�1��С�ڵ���pivot��Ԫ��
		while (i<j && L->data[i]<=pivot) 
			i++;			//��������ɨ��,�ҵ�1������pivot��Ԫ��
		if (i<j)
		{
			tmp=L->data[i];	//L->data[i]��L->data[j]���н���
			L->data[i]=L->data[j];
			L->data[j]=tmp;
		}
		//�������ÿһ�˵Ľ��
		for (int a=0;a<L->length;a++)
			printf("%d ",L->data[a]);
		printf("\n");
	}
	tmp=L->data[0];			//L->data[0]��L->data[j]���н���
	L->data[0]=L->data[j];
	L->data[j]=tmp;
	printf("��׼λ��i=%d\n",i);
}

void main()
{
	SqList *L;
	//ElemType a[]={3,8,2,7,1,5,3,4,6,0};
	ElemType a[]={3,8,2,7,3,5,3,4,6,0};
	CreateList(L,a,10);
	printf("L:");DispList(L);
	printf("ִ���ƶ�����\n");
	move1(L);
	printf("L:");DispList(L);
	DestroyList(L);
}
