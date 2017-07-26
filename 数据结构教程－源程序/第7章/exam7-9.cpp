#include "btree.cpp"
int Level(BTNode *b,ElemType x,int h)
{
	int l;
	if (b==NULL)
		return(0);
	else if (b->data==x)
		return(h);
	else
	{
		l=Level(b->lchild,x,h+1);
		if (l!=0)
			return(l);
		else
			return(Level(b->rchild,x,h+1));
	}
}
void main()
{
	BTNode *b;
	int h;
	ElemType x;
	CreateBTNode(b,"A(B(D(,G)),C(E,F))");
	printf("b:");DispBTNode(b);printf("\n");
	printf("���ֵ:");
	scanf("%c",&x);
	h=Level(b,x,1);
	if (h==0)
		printf("b�в�����%c���\n",x);
	else
		printf("��b��%c���Ĳ��Ϊ%d\n",x,h);
}
