#include "tup.cpp"
int MatAdd(TSMatrix a,TSMatrix b,TSMatrix &c)
{
	int i=0,j=0,k=0;
	ElemType v;
	if (a.rows!=b.rows || a.cols!=b.cols)
		return 0;				  		 //��������������ʱ���ܽ����������
	c.rows=a.rows;c.cols=a.cols; 		 //c����������a����ͬ
	while (i<a.nums && j<b.nums) 		 //����a��b�е�ÿ��Ԫ��
	{	
		if (a.data[i].r==b.data[j].r)	 //�к����ʱ
		{	
			if(a.data[i].c<b.data[j].c)	 //aԪ�ص��к�С��bԪ�ص��к�
			{	
				c.data[k].r=a.data[i].r;//��aԪ����ӵ�c��
				c.data[k].c=a.data[i].c;
				c.data[k].d=a.data[i].d;
				k++;i++;
           	}
           	else if (a.data[i].c>b.data[j].c)//aԪ�ص��кŴ���bԪ�ص��к�
			{	
				c.data[k].r=b.data[j].r;	  //��bԪ����ӵ�c��
               	c.data[k].c=b.data[j].c;
               	c.data[k].d=b.data[j].d;
               	k++;j++;
           	}
           	else					//aԪ�ص��кŵ���bԪ�ص��к�
			{ 	
				v=a.data[i].d+b.data[j].d;
				if (v!=0)			//ֻ����Ϊ0�Ľ����ӵ�c��
				{
					c.data[k].r=a.data[i].r;
					c.data[k].c=a.data[i].c;
					c.data[k].d=v;
					k++;
				}
				i++;j++;
          	 }
		}
     	else if (a.data[i].r<b.data[j].r) //aԪ�ص��к�С��bԪ�ص��к�
		{	
			c.data[k].r=a.data[i].r;	  //��aԪ����ӵ�c��
			c.data[k].c=a.data[i].c;
			c.data[k].d=a.data[i].d;
			k++;i++;
		}
		else							  //aԪ�ص��кŴ���bԪ�ص��к�
		{
			c.data[k].r=b.data[j].r;	  //��bԪ����ӵ�c��
			c.data[k].c=b.data[j].c;
			c.data[k].d=b.data[j].d;
			k++;j++;
     	}
     	c.nums=k;
	}
	return 1;
}
void main()
{
	ElemType a[M][N]={{1,0,3},{0,2,0},{0,0,5}};
	//ElemType b[M][N]={{-1,0,2},{0,-2,0},{1,0,-5}};
	ElemType b[M][N]={{0,0,0},{0,0,0},{0,0,1}};
	TSMatrix x,y,z;
	CreatMat(x,a);
	CreatMat(y,b);
	MatAdd(x,y,z);
	printf("a����Ԫ��:\n");DispMat(x);
	printf("b����Ԫ��:\n");DispMat(y);
	printf("��Ӻ����Ԫ��:\n");DispMat(z);
}