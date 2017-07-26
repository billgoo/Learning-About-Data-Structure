#include "sqlist.cpp" 
void move2(SqList *&L)
{
	int i=0,j=L->length-1;
	ElemType pivot=L->data[0];	//��data[0]Ϊ��׼
	while (i<j)  				//��˳������˽������м�ɨ��,ֱ��i=jΪֹ
	{	
		while (j>i && L->data[j]>pivot) 
			j--;  				//��������ɨ��,��һ��С�ڵ���pivot��data[j]
		L->data[i]=L->data[j];	//�ҵ�������data[j],����data[i]��
		i++;
		while (i<j && L->data[i]<=pivot) 
			i++;				//��������ɨ��,��һ������pivot�ļ�¼data[i]
		L->data[j]=L->data[i];	//�ҵ�������data[i],����data[j]��
		j--;

		//������ʾÿһ�˵Ľ��
		for (int a=0;a<L->length;a++)
			printf("%d ",L->data[a]);
		printf("\n");

	}
	L->data[i]=pivot;
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
	move2(L);
	printf("L:");DispList(L);
	DestroyList(L);
}
