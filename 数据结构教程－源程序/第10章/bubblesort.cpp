#include <stdio.h>
#define MaxSize 20
typedef int KeyType;  	//����ؼ�������
typedef char InfoType[10];
typedef struct       	//��¼����
{
	KeyType key;   		//�ؼ�����
	InfoType data; 		//����������,����ΪInfoType
} RecType;				//����ļ�¼���Ͷ���

void BubbleSort(RecType R[],int n)
{
	int i,j,k;
	RecType tmp;
	for (i=0;i<n-1;i++) 
	{
		for (j=n-1;j>i;j--)	//�Ƚ�,�ҳ�������С�ؼ��ֵļ�¼
			if (R[j].key<R[j-1].key)   
			{
				tmp=R[j];  //R[j]��R[j-1]���н���,����С�ؼ��ּ�¼ǰ��
				R[j]=R[j-1];
				R[j-1]=tmp;
			}
		printf("i=%d: ",i);
		for (k=0;k<n;k++)
			printf("%d ",R[k].key);
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
	BubbleSort(R,n);
	printf("�����:");
	for (i=0;i<n;i++)
		printf("%d ",R[i].key);
	printf("\n");
}


