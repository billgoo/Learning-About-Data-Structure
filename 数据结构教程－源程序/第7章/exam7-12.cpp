#include "btree.cpp"
void AllPath1(BTNode *b)
{
	BTNode *St[MaxSize];
	BTNode *p;
	int flag,i,top=-1;				//ջָ���ó�ֵ
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
			p=NULL;					//pָ��ջ������ǰһ���ѷ��ʵĽ��
			flag=1;					//����b�ķ��ʱ��Ϊ�ѷ��ʹ�
			while (top!=-1 && flag)
			{	
				b=St[top];			//ȡ����ǰ��ջ��Ԫ��
				if (b->rchild==p)	
				{	
					if (b->lchild==NULL && b->rchild==NULL)	//��ΪҶ�ӽ��
					{	//���ջ�����н��ֵ
						for (i=top;i>0;i--)
							printf("%c->",St[i]->data);
						printf("%c\n",St[0]->data);
					}
					top--;
					p=b;			//pָ��շ��ʹ��Ľ��
				}
				else
				{	b=b->rchild;	//bָ���Һ��ӽ��
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
	printf("������д�Ҷ�ӽ�㵽����������:\n");
	AllPath1(b);
}
