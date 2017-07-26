#include <stdio.h>
#define MaxSize 20
typedef int KeyType;  	//����ؼ�������
typedef char InfoType[10];
typedef struct       	//��¼����
{
	KeyType key;   		//�ؼ�����
	InfoType data; 		//����������,����ΪInfoType
} RecType;				//����ļ�¼���Ͷ���
void SelectSort(RecType R[],int n)
{
	int i,j,k,l;
	RecType temp;
	for (i=0;i<n-1;i++)    	 	//����i������
	{
		k=i;
		for (j=i+1;j<n;j++)  	//�ڵ�ǰ������R[i..n-1]��ѡkey��С��R[k]
			if (R[j].key<R[k].key)
				k=j;           	//k����Ŀǰ�ҵ�����С�ؼ������ڵ�λ��
			if (k!=i)          		//����R[i]��R[k]
			{
				temp=R[i];
				R[i]=R[k];
				R[k]=temp;  
			}
		printf("i=%d: ",i);
		for (l=0;l<n;l++)
			printf("%d ",R[l].key);
		printf("\n");
	}
}
void main()
{
	int i,n=10;
	RecType R[MaxSize];
	KeyType a[]={9,8,7,6,5,4,3,2,1,0};
	for (i=0;i<n;i++)
		R[i].key=a[i];
	printf("����ǰ:");
	for (i=0;i<n;i++)
		printf("%d ",R[i].key);
	printf("\n");
	SelectSort(R,n);
	printf("�����:");
	for (i=0;i<n;i++)
		printf("%d ",R[i].key);
	printf("\n");
}


