#include <stdio.h>
#include <string.h>
#define MaxSize 100
typedef char ElemType[10];
typedef struct
{	
	ElemType data;		//������
	int next;			//�α���,ָʾ��һ��Ԫ���������е�λ��
} StaticList[MaxSize];
void CreateList(StaticList L,ElemType a[],int n)//������̬����
{
	int i;
	L[0].next=1;
	for (i=1;i<=n;i++)
	{
		strcpy(L[i].data,a[i-1]);
		L[i].next=i+1;
	}
	L[n].next=0;
}
void InitList(StaticList L)
{
	int j;
	L[0].next=0;			//��Ϊ�ձ�
	for (j=1;j<MaxSize;j++)
		L[j].next=-1;		//-1��ʾ��λ��Ϊ��
}
int ListEmpty(StaticList L)
{
	return(L[0].next==0);
}
int ListLength(StaticList L)
{
	int n=0,j=0;
	while (L[j].next!=0)
	{	n++;
		j=L[j].next;
	}
	return(n);
}
void DispList(StaticList L)
{
	int j=0;
	while (L[j].next!=0)
	{	j=L[j].next;
		printf("%d:%s,%d\n",j,L[j].data,L[j].next);
	}
	printf("\n");
}
int GetElem(StaticList L,int i,ElemType &e)
{
	int k=0,j=L[0].next;
	while (k<i-1 && j!=0)
	{	k++;
		j=L[j].next;
	}
	if (j==0)				//�����ڵ�i�����ݽ��
		return 0;
	else					//���ڵ�i�����ݽ��
	{	strcpy(e,L[j].data);
		return 1;
	}
}
int LocateElem(StaticList L,ElemType e)
{
	int j=L[0].next;
	int n=1;
	while (j!=0 && strcmp(L[j].data,e)!=0)
	{	j=L[j].next;
		n++;
	}
	if (j==0)
		return(0);
	else
		return(n);
}
int ListInsert(StaticList &L,int i,ElemType e)
{
	int j=L[0].next,j1,j2,k;
	if (i==1)						//������Ϊ��һ�����
	{	if (j==0)					//ԭ����Ϊ��
		{  	strcpy(L[1].data,e);
			L[0].next=1;
			L[1].next=0;
			return 1;
		}
		else						//ԭ����Ϊ��
		{	k=j+1;
			while (k!=j)			//��������ѭ���Ҵ��e�Ŀ�λ��
				if (L[k].next==-1)
					break;
				else
					k=(k+1)%MaxSize;
			if (k!=j)				//���������ҵ���һ����λ��k���e
			{	strcpy(L[k].data,e);
				L[k].next=L[0].next;
				L[0].next=k;
				return 1;
			}
			else return 0;			//��������,�����
		}
	}
	else	//������Ϊ�������
	{	k=0;
		while (k<i-2 && j!=0)		//���ҵ�i-1�����
		{	k++;
			j=L[j].next;
		}
		if (j==0)					//δ�ҵ���i-1�����
			return 0;
		else						//�ҵ���i-1�����
		{	j1=j;					//��j1����j
			j2=L[j].next;			//��j2����ԭ��L[j]��next��
			k=j+1;
			while (k!=j)			//��������ѭ���Ҵ��e�Ŀ�λ��
				if (L[k].next==-1)
					break;
				else
					k=(k+1)%MaxSize;
			if (k!=j)				//���������ҵ���һ����λ��k���e
			{	strcpy(L[k].data,e);
				L[j1].next=k;
				L[k].next=j2;
				return 1;
			}
			else return 0;			//��������,�����
		}
	}
}
int ListDelete(StaticList L,int i,ElemType &e)
{
	int j=L[0].next,j1,k;
	if (L[0].next==0)				//�ձ�ʱɾ��ʧ��
		return(0);	
	if (i==1)						//ɾ����1�����
	{	j1=L[0].next;
		L[0].next=L[j1].next;
		strcpy(e,L[j1].data);
		L[j1].next=-1;
		return(1);
	}
	else							//ɾ���������
	{	k=0;
		while (k<i-2 && j!=0)		//���ҵ�i-1�����
		{	k++;
			j=L[j].next;
		}
		if (j==0)					//δ�ҵ���i-1�����
			return 0;
		else						//�ҵ���i-1�����L[j]
		{	if (L[j].next==0)		//�����ڵ�i�����
				return(0);	
			j1=L[j].next;
			L[j].next=L[j1].next;
			strcpy(e,L[j1].data);
			L[j1].next=-1;
			return 1;
		}
	}
}
void main()
{
	ElemType a[7]={"�ű�","����","��Ӣ","�»�","����","��ǿ","��Ƽ"};
	ElemType e;
	int i;
	StaticList L;
	InitList(L);
	CreateList(L,a,7);
	printf("L:\n");DispList(L);
	strcpy(e,"�»�");
	i=LocateElem(L,e);
	printf("i=%d\n",i);
	ListDelete(L,i,e);
	printf("L:\n");DispList(L);
	strcpy(e,"����");
	ListInsert(L,3,e);
	printf("L:\n");DispList(L);
}
