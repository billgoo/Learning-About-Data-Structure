#include "sqlist.cpp"   //�������Ա���˳����ʾ
void unionList(SqList *LA,SqList *LB,SqList *&LC) 
{
	int lena,i;
	ElemType e;
	InitList(LC);
	for (i=1;i<=ListLength(LA);i++)	//��LA������Ԫ�ز��뵽Lc��
	{	
		GetElem(LA,i,e);
		ListInsert(LC,i,e);
	}
	lena=ListLength(LA);    			//�����Ա�LA�ĳ���
	for (i=1;i<=ListLength(LB);i++) 
	{	
		GetElem(LB,i,e); 				//ȡLB�е�i������Ԫ�ظ���e
		if (!LocateElem(LA,e)) 
			ListInsert(LC,++lena,e); 	//LA�в����ں�e��ͬ��,����뵽LC��
	}
}

void main()
{
	SqList *LA,*LB,*LC;
	InitList(LA);
	InitList(LB);
	//����LA={1,3,2}
	ListInsert(LA,1,1);
	ListInsert(LA,2,3);
	ListInsert(LA,3,2);
	printf("LA:");DispList(LA);
	//����LB={1,4,2}
	ListInsert(LB,1,1);
	ListInsert(LB,2,4);
	ListInsert(LB,3,2);
	printf("LB:");DispList(LB);
	unionList(LA,LB,LC);
	printf("LC=LA��LB\n");
	printf("LC:");DispList(LC);
	DestroyList(LA);
	DestroyList(LB);
	DestroyList(LC);
}