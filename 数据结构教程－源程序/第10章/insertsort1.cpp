#include <stdio.h>
#define MaxSize 20
typedef int KeyType;  	//����ؼ�������
typedef char InfoType[10];
typedef struct       	//��¼����
{
	KeyType key;   		//�ؼ�����
	InfoType data; 		//����������,����ΪInfoType
} RecType;				//����ļ�¼���Ͷ���

void InsertSort1(RecType R[],int n) //��R[0..n-1]�������������ֱ�Ӳ�������
{
	int i,j,low,high,mid;
	RecType tmp;
	for (i=1;i<n;i++) 
	{
		tmp=R[i];
		low=0;high=i-1;
		while (low<=high)
		{
			mid=(low+high)/2;
			if (tmp.key<R[mid].key)
				high=mid-1;
			else
				low=mid+1;
		}
		for (j=i-1;j>=high+1;j--)
			R[j+1]=R[j];
		R[high+1]=tmp;
		printf("i=%d: ",i);
		for (j=0;j<n;j++)
			printf("%d ",R[j].key);
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
	InsertSort1(R,n);
	printf("�����:");
	for (i=0;i<n;i++)
		printf("%d ",R[i].key);
	printf("\n");
}


