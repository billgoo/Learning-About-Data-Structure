#include <stdio.h>
void Hanoi(int n,char a,char b,char c)
{
	if (n==1) 
		printf("\t����%d����Ƭ��%c�ƶ���%c\n",n,a,c);
    else 
	{
		Hanoi(n-1,a,c,b);
		printf("\t����%d����Ƭ��%c�ƶ���%c\n",n,a,c);
		Hanoi(n-1,b,a,c);
	}
}
void main()
{
	int n=3;
	printf("  %d����Ƭ�ƶ�����:\n",n);
	Hanoi(n,'X','Y','Z');
}