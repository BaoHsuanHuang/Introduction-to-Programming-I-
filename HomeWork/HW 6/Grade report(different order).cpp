#include <stdio.h>
#include <stdlib.h>
//#include "function.h"

typedef struct
{
   int ID;
   int Chinese, English, math, science;
   int total;
} Grade;

void sortGrade(Grade *gList, int n, char *order);
int cmp_a(const void* a, const void* b);
int cmp_d(const void* a, const void* b);


int main(){
    int n, i;
    char order[20];
    Grade gradeList[1000];
    scanf("%d%s", &n, order);
    for(i = 0; i < n; i++)
        scanf("%d%d%d%d%d", &gradeList[i].ID, &gradeList[i].Chinese,&gradeList[i].English, &gradeList[i].math, &gradeList[i].science);
    sortGrade(gradeList, n, order);
    for(i = 0; i < n; i++)
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", gradeList[i].ID, gradeList[i].total,gradeList[i].Chinese, gradeList[i].English,gradeList[i].math, gradeList[i].science);
    return 0;
}

int cmp_a( const void * a,const void * b)
{
	Grade * pa = (Grade *) a;
	Grade * pb = (Grade *) b;
	
	if( (*pa).total > (*pb).total ) return 1;
	if( (*pa).total < (*pb).total ) return -1;
	else{
		if( (*pa).Chinese > (*pb).Chinese ) return 1;
		if( (*pa).Chinese < (*pb).Chinese ) return -1;
		else{
            if((*pa).English > (*pb).English) return 1;
            if((*pa).English < (*pb).English) return -1;
            else{
                if((*pa).math > (*pb).math) return 1;
                if((*pa).math < (*pb).math) return -1;
                else{
                    if((*pa).science > (*pb).science) return 1;
                    if((*pa).science < (*pb).science) return -1;
                    else{
                        if((*pa).ID > (*pb).ID) return 1;
                        if((*pa).ID < (*pb).ID) return -1;
                        else return 0;
                    }
                }
            }
        }
	}
}

int cmp_d(const void* a, const void* b){
    Grade *pa = (Grade*)a;
    Grade *pb = (Grade*)b;
    if((*pa).total < (*pb).total) return 1;
    if((*pa).total > (*pb).total) return -1;
    else {
        if((*pa).Chinese < (*pb).Chinese) return 1;
        if((*pa).Chinese > (*pb).Chinese) return -1;
        else{
            if((*pa).English < (*pb).English) return 1;
            if((*pa).English > (*pb).English) return -1;
            else{
                if((*pa).math < (*pb).math) return 1;
                if((*pa).math > (*pb).math) return -1;
                else{
                    if((*pa).science < (*pb).science) return 1;
                    if((*pa).science > (*pb).science) return -1;
                    else{
                        if((*pa).ID > (*pb).ID) return 1;
                        if((*pa).ID < (*pb).ID) return -1;
                        else return 0;
                    }
                }
            }
        }
    }
}


void sortGrade(Grade *gList, int n, char *order)
{
	//* gList.total = *gList.Chinese + * gList.English + * gList.math + * gList.science;
	int i;
	for(i=0;i<n;i++){
		gList[i].total = gList[i].Chinese + gList[i].English + gList[i].math + gList[i].science ;
	}
	
	if( order[0] == 'a'){
		qsort(gList,n,sizeof(Grade),cmp_a);
	}
	else{
		qsort(gList,n,sizeof(Grade),cmp_d);
	}	
}









