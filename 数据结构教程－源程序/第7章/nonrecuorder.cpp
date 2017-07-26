#include "btree.cpp"
void PreOrder1(BTNode *b)	//����ǵݹ�����㷨
{
	BTNode *St[MaxSize],*p;
	int top=-1;
	if (b!=NULL) 
	{   
		top++;						//������ջ
		St[top]=b;
		while (top>-1)				//ջ��Ϊ��ʱѭ��
		{
			p=St[top];				//��ջ�����ʸý��
			top--;
			printf("%c ",p->data);
			if (p->rchild!=NULL)	//�Һ��ӽ���ջ
			{
				top++;
               	St[top]=p->rchild;
			}
			if (p->lchild!=NULL)	//���ӽ���ջ
			{
				top++;
               	St[top]=p->lchild;
			}
		}
		printf("\n");
	}
}
void InOrder1(BTNode *b)	//����ǵݹ�����㷨
{
	BTNode *St[MaxSize],*p;
	int top=-1;
	if (b!=NULL)
	{
		p=b;
		while (top>-1 || p!=NULL)		//����*b����������
		{
			while (p!=NULL)				//ɨ��*p���������㲢��ջ
			{
				top++;
				St[top]=p;
				p=p->lchild;
			}
			//ִ�е��˴�ʱ��ջ��Ԫ��û�����ӻ����������ѷ��ʹ�
			if (top>-1)
			{	
				p=St[top];				//��ջ*p���
				top--;
				printf("%c ",p->data);	//����֮
				p=p->rchild;			//ɨ��*p���Һ��ӽ��
			}
		}
		printf("\n");
	}
}
void PostOrder1(BTNode *b)		//����ǵݹ�����㷨
{
	BTNode *St[MaxSize];
	BTNode *p;
	int flag,top=-1;				//ջָ���ó�ֵ
	if (b!=NULL)
	{
		do
		{
			while (b!=NULL)			//��*b�����������ջ
			{
				top++;
				St[top]=b;
				b=b->lchild;
			}
			//ִ�е��˴�ʱ��ջ��Ԫ��û�����ӻ����������ѷ��ʹ�
			p=NULL;					//pָ��ջ������ǰһ���ѷ��ʵĽ��
			flag=1;					//����b�ķ��ʱ��Ϊ�ѷ��ʹ�
			while (top!=-1 && flag)
			{	b=St[top];			//ȡ����ǰ��ջ��Ԫ��
				if (b->rchild==p)	
				{	
					printf("%c ",b->data);	//����*b���
					top--;
					p=b;			//pָ��շ��ʹ��Ľ��
				}
				else
				{	
					b=b->rchild;	//bָ���Һ��ӽ��
					flag=0;			//����δ�����ʵı��
				}
			}
		} while (top!=-1);
		printf("\n");
	} 
}
void main()
{
	BTNode *b;
	CreateBTNode(b,"A(B(D(,G)),C(E,F))");
	printf("b:");DispBTNode(b);printf("\n");
	printf("�����������:");PreOrder1(b);
	printf("�����������:");InOrder1(b);
	printf("�����������:");PostOrder1(b);
}
