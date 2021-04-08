#include <stdio.h>
typedef struct student
{
	char name[9];
	int marks[10];
	float score;//final normalized score
	char grade;
}student;
typedef struct gradebook
{
	char cn[20];//course name
	int m;//number of students
	int k;//number of subjects
	float weights[10];
	student s[10];
}gb;
int input_n()
{
	int a = 0;
	scanf("%d",&a);
	return a;
}
student input_one_student(student s,int no_of_subjects)
{
	scanf("%s",s.name);
	for( int z=0; z<no_of_subjects; z++)
	{
		scanf("%d",&s.marks[z]);
	}
	return s;
}
gb input_n_students(gb g)
{
	scanf("%s", g.cn);
	scanf("%d%d", &g.m, &g.k);
	for(int z=0; z<g.k; z++)
	{
		scanf("%f",&g.weights[z]);
	}

	for(int j=0; j<g.m; j++)
	{
		g.s[j] = input_one_student(g.s[j],g.k);
	}
	return g;
}
float normalize(float W,int m[],float weights[],int no_of_subjects)
{
	float total_marks = 0.0;
	for(int z=0; z< no_of_subjects; z++)
	{
		total_marks = total_marks + (float)m[z]*weights[z]; 
	}
	total_marks = total_marks/W;
	return total_marks;
}
char findgrade(float sc)//sc stands for score
{
	char gr = ' ';
	if(sc >= 0.0 && sc < 60.0)
	{
		gr = 'F';
	}
	else if(sc >=60.0 && sc <70)
	{
		gr = 'D';
	}
	else if(sc >= 70 && sc <80)
	{
		gr = 'C';
	}
	else if(sc >=80 && sc <90)
	{
		gr = 'B';
	}
	else
	{
		gr = 'A';
	}
	return gr;
}
student compute_grade_one_student(float weights[],student s, float W,int no_of_subjects)
{
	s.score = normalize(W,s.marks,weights,no_of_subjects);
	s.grade = findgrade(s.score);
	return s;
}
gb compute_grade_n_students(gb g)
{
	//find sum of weights
	float W = 0;
	for(int j=0; j<g.k; j++)
	{
		W = W + g.weights[j];
	}
	for(int j=0; j<g.m; j++)
	{
		g.s[j] = compute_grade_one_student(g.weights,g.s[j],W,g.k);
	}
	return g;
}
void print_grade_one_student(student s)
{
	printf("%s %.2f %c\n",s.name,s.score,s.grade);
}
void print_grade_n_students(gb g)
{
	printf("%s\n",g.cn);
	for(int j=0; j<g.m; j++)
	{
		print_grade_one_student(g.s[j]);
	}
}
int main()
{
	int n = 0;//number of gradebooks
	n = input_n();
	gb g[n];
	for(int i = 0; i<n; i++)
	{
		g[i] = input_n_students(g[i]);
		g[i] = compute_grade_n_students(g[i]);
	}
	for(int i=0; i<n; i++)
	{
		printf("\n");
		print_grade_n_students(g[i]);
	}
	return 0;
}
