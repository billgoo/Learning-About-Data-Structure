#include "sqstack.cpp"
bool symmetry(ElemType str[])
{
	int i;  ElemType e;
	SqStack *st;
	InitStack(st);				//��ʼ��ջ
	for (i=0;str[i]!='\0';i++)	//��������Ԫ�ؽ�ջ
		Push(st,str[i]);		//Ԫ�ؽ�ջ
	for (i=0;str[i]!='\0';i++)
	{
		Pop(st,e);				//��ջԪ��e
		if (str[i]!=e)			//��e�뵱ǰ��Ԫ�ز�ͬ���ǶԳƴ�
		{
			DestroyStack(st);	//����ջ
			return false;
		}
	}
	DestroyStack(st);			//����ջ
	return true;
}

void main()
{
	ElemType str[]="1234321";
	if (symmetry(str))
		printf("%s�ǶԳƴ�\n",str);
	else
		printf("%s���ǶԳƴ�\n",str);
}