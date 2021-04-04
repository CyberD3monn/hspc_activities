#include<stdio.h>
typedef struct fraction
{
	int n;
	int d[100];
	int sum_n;
	int sum_d;
}fraction;
int input(fraction f[])
{
	int op = 0;
	scanf("%d",&op);
	
	for(int i = 0;i < op; i++)
	{
		scanf("%d",&f[i].n);
		for(int j =0;j < f[i].n ;j++)
		{
			scanf("%d",&f[i].d[j]);
		}
	}
	return op;
}
void add(fraction f[],int s)
{
	void simplify(fraction f[],int s);
	for(int i=0;i < s;i++)
	{
		f[i].sum_n = 0;
		f[i].sum_d = 1;
		for(int j = 0;j < f[i].n;j++)
		{
			int prod =1;
			if(f[i].n==1)
			{
				f[i].sum_n = 1;
				f[i].sum_d = f[i].d[j];
				continue;
			}
			for(int k =0;k < f[i].n; k++)
			{
				if(j != k)
				{
					prod = prod * f[i].d[k];
				}
			}
			f[i].sum_n = f[i].sum_n + prod;
			f[i].sum_d = f[i].sum_d * f[i].d[j];
		}
		simplify(f,s);
	}
}
int findhcf(int a, int b)
{
	int hcf = 1;
	int min =0;
	if(a<b)
	{
		min = a;
	}
	else
	{
		min = b;
	}
	for(int i = 2;i<=min;i++)
	{
		if(a%i == 0 && b%i == 0)
		{
			hcf = i;
		}
	}
	return hcf;
}
void simplify(fraction f[],int s)
{
	for(int i = 0;i < s; i++)
	{
		int hcf = findhcf(f[i].sum_n,f[i].sum_d);
		f[i].sum_n = f[i].sum_n/hcf;
		f[i].sum_d = f[i].sum_d/hcf;
	}
}
void display(fraction f[],int s)
{
	for(int i =0; i<s ;i++)
	{
		for(int j=0; j<f[i].n;j++)
		{
			if(j!=f[i].n-1)
			{
				printf("1/%d + ",f[i].d[j]);
			}
			else
			{
				printf("1/%d = ",f[i].d[j]);
			}
		}
		printf("%d/%d\n",f[i].sum_n,f[i].sum_d);
	}
}
int main()
{
	fraction f[100];
	int size = input(f);
	add(f,size);
	display(f,size);
	return 0;
}
