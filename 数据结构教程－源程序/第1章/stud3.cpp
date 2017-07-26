#include <stdio.h>
#define MaxStud 50		//ѧ���������Ϊ50
#define MaxCour 300		//ѧ���ɼ���¼�����Ϊ50*6
struct stud1
{
	int no;			//ѧ��
	char name[10];	//����
	int bno;		//���
};
struct stud2
{
	int no;			//ѧ��
	int cno;		//�γ̱��
	int deg;		//����
};
double studavg(struct stud2 s2[],int m,int i)	//��ѧ��Ϊi��ѧ����ƽ����
{
	int j,n=0;				//nΪѧ��Ϊi��ѧ��ѡѧ�γ���
	double sum=0;			//ѧ��Ϊi��ѧ���ܷ�
	for (j=0;j<m;j++)
		if (s2[j].no==i)	//ѧ��Ϊiʱͳ��
		{
			n++;
			sum+=s2[j].deg;
		}
	return(sum/n);
}
double couravg(struct stud2 s2[],int m,int i)	//����Ϊi�Ŀγ̵�ƽ����
{
	int j,n=0;				//nΪ���Ϊi�Ŀγ�ѡ������
	double sum=0;			//���Ϊi�Ŀγ��ܷ�
	for (j=0;j<m;j++)
	{
		if (s2[j].cno==i)	//�γ̱��Ϊiʱͳ��
		{
			n++;
			sum+=s2[j].deg;
		}
	}
	return(sum/n);
}
void allavg(struct stud1 s1[],int n,struct stud2 s2[],int m)	//��ѧ��ƽ���ֺͿγ�ƽ����
{
	int i,j;
	printf("ѧ��ƽ����:\n");
	printf("  ѧ��     ���� ƽ����\n");
	i=0;
	while (i<n)
	{
		j=s1[i].no;
		printf("%4d %10s %g\n",s1[i].no,s1[i].name,studavg(s2,m,j));
		i++;
	}
	printf("�γ�ƽ����:\n");
	for (i=1;i<=6;i++)
		printf(" �γ�%d:%g\n",i,couravg(s2,m,i));
}

void main()
{
	int n=7;		//ѧ����¼����
	int m=21;		//ѧ���ɼ���¼��
	struct stud1 s1[MaxStud]={
		{1,"�ű�",9901},
		{8,"����",9902},
		{34,"��Ӣ",9901},
		{20,"�»�",9902},
		{12,"����",9901},
		{26,"��ǿ",9902},
		{5,"��Ƽ",9901}};
	struct stud2 s2[MaxCour]={	//�涨�γ̵ı�Ŵ�1��6,ͬһѧ���ɼ���¼�������
		{1,1,67},
		{1,2,98},
		{1,4,65},
		{8,1,98},
		{8,3,90},
		{8,6,67},
		{34,2,56},
		{34,4,65},
		{34,6,77},
		{20,1,68},
		{20,2,92},
		{20,3,64},
		{12,4,76},
		{12,5,75},
		{12,6,78},
		{26,1,67},
		{26,5,78},
		{26,6,62},
		{5,1,94},
		{5,2,92},
		{5,6,89}};
	allavg(s1,n,s2,m);
}