#include <stdio.h>
#include <stdlib.h>

typedef struct{
	char name[21];
	int score;
	int order;
}Student;

Student student[100000];
int cmp(const void * a,const void * b);

int main(void)
{
	int n;
	int i;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%s%d",student[i].name,&(student[i].score));
		student[i].order = i;
	}
	qsort(student,n,sizeof(Student),cmp);
	
	for(i=0;i<n;i++){
		printf("%s\n",student[i].name);
	}
	
	return 0;
}

int cmp(const void * a,const void * b)
{
	Student * va = (Student *)a;
	Student * vb = (Student *)b;
	
	if(va->score != vb->score) return vb->score - va->score;
	else return va->order - vb->order;
}
