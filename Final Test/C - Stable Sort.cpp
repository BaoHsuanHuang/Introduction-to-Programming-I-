#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char name[21];
	int score;
	int order;
}Student;

int cmp(const void* a,const void* b);

int main(void)
{
	int N;
	scanf("%d",&N);
	
	Student* student = (Student*)malloc(N * sizeof(Student));
	
	int i;
	for(i=0;i<N;i++){
		scanf("%s%d",student[i].name,&(student[i].score));
		student[i].order = i;
	}

	qsort(student,N,sizeof(Student),cmp);

	for(i=0;i<N;i++){
		printf("%s\n",student[i].name);
	}
	
	return 0;
}

int cmp(const void* a,const void* b)
{
	Student *va = (Student * )a;
	Student *vb = (Student * )b;
	
	//if( va->score < vb->score) return 1;
	//else if( va->score > vb->score) return -1;
	//else return 0;											// Point
	
	if(va->score != vb->score) return vb->score - va->score;
	else return va->order - vb->order;
}
