#include <stdio.h>
int fun(int n)
{
	if (n==1) 					//���1
		return(1);				//���2
	else 						//���3
		return(fun(n-1)*n);		//���4
}
void main()
{
	printf("10!=%d\n",fun(10));
}