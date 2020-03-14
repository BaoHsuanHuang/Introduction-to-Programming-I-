
point 1 : *(gList+i).total = gList[i].total
point 2 : 傳陣列名稱(gradeList)進去sortGrade這個function，代表傳進'開頭位置' 



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
int cmp_a(const void * a, const void * b);
int cmp_d(const void * a, const void * b);

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

int cmp_a(const void * a, const void * b)
{
	Grade * va = (Grade *)a;
	Grade * vb = (Grade *)b;
	
	if(va->total > vb->total) return 1;
	else if(va->total < vb->total) return -1;
	else{
		if(va->Chinese > vb->Chinese) return 1;
		else if(va->Chinese < vb->Chinese) return -1;
		else{
			if(va->English > vb->English) return 1;
			else if(va->English < vb->English) return -1;
			else{
				if(va->math > vb->math) return 1;
				else if(va->math < vb->math) return -1;
				else{
					if(va->science > vb->science) return 1;
					else if(va->science < vb->science) return -1;
					else{
						if(va->ID > vb->ID) return 1;
						else if(va->ID > vb->ID) return -1;
						else return 0;
					}
				}
			}
		}
	}
}

int cmp_d(const void * a, const void * b)
{
	Grade * va = (Grade *)a;
	Grade * vb = (Grade *)b;
	
	if(va->total > vb->total) return -1;
	else if(va->total < vb->total) return 1;
	else{
		if(va->Chinese > vb->Chinese) return -1;
		else if(va->Chinese < vb->Chinese) return 1;
		else{
			if(va->English > vb->English) return -1;
			else if(va->English < vb->English) return 1;
			else{
				if(va->math > vb->math) return -1;
				else if(va->math < vb->math) return 1;
				else{
					if(va->science > vb->science) return -1;
					else if(va->science < vb->science) return 1;
					else{
						if(va->ID > vb->ID) return 1;
						else if(va->ID > vb->ID) return -1;
						else return 0;
					}
				}
			}
		}
	}
}


void sortGrade(Grade *gList, int n, char *order)
{
	int i;
	for(i=0;i<n;i++){
		gList[i].total = gList[i].Chinese + gList[i].English + gList[i].math + gList[i].science;		//point
	}
	
	if(order[0] == 'a'){
		qsort(gList,n,sizeof(Grade),cmp_a);		//point
	}
	else if(order[0] == 'd'){
		qsort(gList,n,sizeof(Grade),cmp_d);
	}
	
}



