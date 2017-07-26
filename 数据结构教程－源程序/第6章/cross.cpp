#include <stdio.h>
#include <malloc.h>
#define M 3         			//������
#define N 3            			//������
#define Max ((M)>(N)?(M):(N))   //�������нϴ���
typedef int ElemType;
typedef struct mtxn 
{ 
	int row;					//�к�
	int col;					//�к�
   	struct mtxn *right,*down;	//���Һ����µ�ָ��
	union 
	{
		ElemType value;
		struct mtxn *link;
	} tag;
} MatNode;			//ʮ���������Ͷ���
void CreatMat(MatNode *&mh,ElemType a[][N])
{
	int i,j;
	MatNode *h[Max],*p,*q,*r;
	mh=(MatNode *)malloc(sizeof(MatNode));//����ʮ�������ͷ�ڵ�
	mh->row=M;mh->col=N;
	r=mh;					//rָ��β�ڵ�
	for (i=0;i<Max;i++)		//����β�巨����ͷ�ڵ�h1,h2,��ѭ������
	{
		h[i]=(MatNode *)malloc(sizeof(MatNode));
		h[i]->down=h[i]->right=h[i];		//��down��right������Ϊѭ����
		r->tag.link=h[i];					//��h[i]�ӵ�������
		r=h[i];
	}
	r->tag.link=mh;							//��Ϊѭ������
	for (i=0;i<M;i++)						//����ÿһ��
	{
		for (j=0;j<N;j++)					//����ÿһ��
		{
			if (a[i][j]!=0)					//�������Ԫ��
			{
				p=(MatNode *)malloc(sizeof(MatNode));	//����һ���½ڵ�
				p->row=i;p->col=j;p->tag.value=a[i][j];
				q=h[i];      					//�������б��еĲ���λ��
                while (q->right!=h[i] && q->right->col<j) 
                  	q=q->right;
				p->right=q->right;q->right=p;	//����б�Ĳ���
				q=h[j];      					//�������б��еĲ���λ��
				while (q->down!=h[j] && q->down->row<i) 
					q=q->down;
				p->down=q->down;q->down=p;  	//����б�Ĳ���
			}
		}
	}
}
void DispMat(MatNode *mh)
{
	MatNode *p,*q;
	printf("��=%d  ��=%d\n", mh->row,mh->col);
	p=mh->tag.link;
	while (p!=mh) 
	{	
		q=p->right;
		while (p!=q) 		//���һ�з���Ԫ��
		{
			printf("%d\t%d\t%d\n", q->row,q->col,q->tag.value);
			q=q->right;
		}
		p=p->tag.link;
	}
}
//�����������ڵ���
void main()
{
	ElemType a[M][N]={{1,0,3},{0,2,0},{0,0,5}};
	ElemType b[M][N]={{-1,0,2},{0,-2,0},{1,0,-5}};
	MatNode *mx,*my;
	CreatMat(mx,a);
	CreatMat(my,b);
	printf("a��ʮ������:\n");DispMat(mx);
	printf("b��ʮ������:\n");DispMat(my);
}
