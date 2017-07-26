#include <stdio.h>
#define MaxStud 50	//ѧ���������Ϊ50
struct stud
{
	int no;			//ѧ��
	char name[10];	//����
	int bno;		//���
	int deg1;		//�γ�1����
	int deg2;		//�γ�2����
	int deg3;		//�γ�3����
	int deg4;		//�γ�4����
	int deg5;		//�γ�5����
	int deg6;		//�γ�6����
};
double studavg(struct stud s[],int i)	//��s[i]ѧ����ƽ����
{
	int m=0;			//s[i]ѧ��ѡѧ�γ���
	double sum=0;		//s[i]ѧ���ܷ�
	if (s[i].deg1!=-1) 
	{
		m++;
		sum+=s[i].deg1;
	}
	if (s[i].deg2!=-1) 
	{
		m++;
		sum+=s[i].deg2;
	}
	if (s[i].deg3!=-1) 
	{
		m++;
		sum+=s[i].deg3;
	}
	if (s[i].deg4!=-1) 
	{
		m++;
		sum+=s[i].deg4;
	}
	if (s[i].deg5!=-1) 
	{
		m++;
		sum+=s[i].deg5;
	}
	if (s[i].deg6!=-1) 
	{
		m++;
		sum+=s[i].deg6;
	}
	return(sum/m);
}
double couravg(struct stud s[],int n,int i)	//���i�ſγ̵�ƽ����
{
	int j,m=0;				//mΪ��i�ſγ�ѡ������
	double sum=0;			//��i�ſγ��ܷ�
	switch(i)
	{
	case 1:for (j=0;j<n;j++)
			   if (s[j].deg1!=-1)
			   {
				   m++;
				   sum+=s[j].deg1;
			   }
			   break;
	case 2:for (j=0;j<n;j++)
			   if (s[j].deg2!=-1)
			   {
				   m++;
				   sum+=s[j].deg2;
			   }
			   break;
	case 3:for (j=0;j<n;j++)
			   if (s[j].deg3!=-1)
			   {
				   m++;
				   sum+=s[j].deg3;
			   }
			   break;
	case 4:for (j=0;j<n;j++)
			   if (s[j].deg4!=-1)
			   {
				   m++;
				   sum+=s[j].deg4;
			   }
			   break;
	case 5:for (j=0;j<n;j++)
			   if (s[j].deg5!=-1)
			   {
				   m++;
				   sum+=s[j].deg5;
			   }
			   break;
	case 6:for (j=0;j<n;j++)
			   if (s[j].deg6!=-1)
			   {
				   m++;
				   sum+=s[j].deg6;
			   }
			   break;
	}
	return(sum/m);
}
void allavg(struct stud s[],int n)	//��ѧ��ƽ���ֺͿγ�ƽ����
{
	int i;
	printf("ѧ��ƽ����:\n");
	printf("  ѧ��     ���� ƽ����\n");
	for (i=0;i<n;i++)
	{
		printf("%4d %10s %g\n",s[i].no,s[i].name,studavg(s,i));
	}
	printf("�γ�ƽ����:\n");
	for (i=1;i<=6;i++)
		printf(" �γ�%d:%g\n",i,couravg(s,n,i));
}
void main()
{
	int n=7;		//ѧ����¼����
	struct stud s[MaxStud]={
		{1,"�ű�",9901,67,98,-1,65,-1,-1},
		{8,"����",9902,98,-1,90,-1,67},
		{34,"��Ӣ",9901,-1,56,-1,65,-1,77},
		{20,"�»�",9902,68,92,64,-1,-1,-1},
		{12,"����",9901,-1,-1,-1,76,75,78},
		{26,"��ǿ",9902,67,-1,-1,-1,78,62},
		{5,"��Ƽ",9901,94,92,-1,-1,-1,89}};
	allavg(s,n);

}