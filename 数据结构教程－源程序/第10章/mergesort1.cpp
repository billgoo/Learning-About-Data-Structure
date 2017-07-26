#include <stdio.h>
#include <malloc.h>
#define MaxSize 20
typedef int KeyType;  	//����ؼ�������
typedef char InfoType[10];
typedef struct       	//��¼����
{
	KeyType key;   		//�ؼ�����
	InfoType data; 		//����������,����ΪInfoType
} RecType;				//����ļ�¼���Ͷ���

void Merge(RecType R[],int low,int mid,int high) 
{
	RecType *R1;
	int i=low,j=mid+1,k=0; //k��R1���±�,i��j�ֱ�Ϊ��1��2�ε��±�
	R1=(RecType *)malloc((high-low+1)*sizeof(RecType));  //��̬����ռ�
	while (i<=mid && j<=high)     	//�ڵ�1�κ͵�2�ξ�δɨ����ʱѭ��
		if (R[i].key<=R[j].key)    	//����1���еļ�¼����R1��
		{
			R1[k]=R[i];
			i++;k++; 
		}
		else                       		//����2���еļ�¼����R1��
		{
			R1[k]=R[j];
			j++;k++; 
		}
	while (i<=mid)          	       	//����1�����²��ָ��Ƶ�R1
	{ 
		R1[k]=R[i];
		i++;k++; 
	}
    while (j<=high)                	//����2�����²��ָ��Ƶ�R1
	{
		R1[k]=R[j];
		j++;k++;  
	}
    for (k=0,i=low;i<=high;k++,i++) //��R1���ƻ�R��
	    R[i]=R1[k];
} 
void MergeSortDC(RecType R[],int low,int high)
//��R[low..high]���ж�·�鲢����
{
	int mid;
	if (low<high)
	{	mid=(low+high)/2;
		MergeSortDC(R,low,mid);
		MergeSortDC(R,mid+1,high);
		Merge(R,low,mid,high);
	}
}
void MergeSort1(RecType R[],int n)	//�Զ����µĶ�·�鲢�㷨
{
	MergeSortDC(R,0,n-1);
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
	MergeSort1(R,n);
	printf("�����:");
	for (i=0;i<n;i++)
		printf("%d ",R[i].key);
	printf("\n");
}


