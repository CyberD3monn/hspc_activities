#include<stdio.h>
#include<math.h>
typedef struct point
{
	double x;
double y;
}point;
typedef struct size
{
	point p[3];
}size;
int readno()
{
	int n;
	scanf("%d",&n);
	return n;
}
void readp(size n[] ,int i)
{	
	//reading a set of 3 points
for(int j=0;j < 3; j++)
{
	//printf("Enter the x coordinate \n");
	scanf("%lf",&n[i].p[j].x);
	//printf("Enter the y coordinate\n");
	scanf("%lf",&n[i].p[j].y);
}
}
double distance(point p1, point p2)
{
	double dist =sqrt(pow((p2.x-p1.x),2)+pow((p2.y-p1.y),2));
	return dist;
}
double area(double length,double breadth)
{
return length*breadth;
}
void display(size n[],double a ,int i)
{
	printf("Area of rectangle with vertices (%lf,%lf),(%lf,%lf),(%lf,%lf) is %lf",n[i].p[0].x,
n[i].p[0].x, n[i].p[1].x , n[i].p[1].y , n[i].p[2].x , n[i].p[2].y );
}
int main()
{
	int sz = readno();
	size n[sz];
double areas[sz];
	for(int i =0;i< sz; i++)
	{
		readp(n,i);
	}
	
	double l,b;
	for(int k=0;k< sz;k++)
	{
		l=b=0.0;
		l = distance(n[k].p[0], n[k].p[1]);
		b = distance(n[k].p[1],n[k].p[2]);
		areas[k] = area(l,b);
	}	
	
	for(int q=0;q<sz;q++)
	{
		display(n,areas[q],q);
	}
return 0;
}
