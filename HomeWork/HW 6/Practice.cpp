// Distance on 2D plane
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//#include "function.h"

typedef struct {
    int x;
    int y;
} Point;

Point * ones_vec_1(int length);
float compute_distance(Point* a, int first_id, int second_id);


int main(void)
{
   Point *point_array;
   int i, length, N;
   float ans;

   scanf("%d", &length);
   // give point_array memory and get first element address
   point_array = ones_vec_1(length);

   scanf("%d", &N);
   for (i = 0; i < N; i++){
      int first, second;
      scanf("%d %d", &first, &second);
      // compute distance of two points
      ans = compute_distance(point_array, first, second);
      printf("%.3f\n", ans);
   }

   return 0;
}

Point * ones_vec_1(int length)
{
	int i;
	Point * array = (Point *)malloc(sizeof(Point)*length);
	
	for(i=0;i<length;i++){
		scanf("%d%d",&array[i].x,&array[i].y);
	}
	
	return array;
}

float compute_distance(Point* a, int first_id, int second_id)
{
	float x , y, ans;
	x = (a[first_id].x - a[second_id].x) * (a[first_id].x - a[second_id].x);
	y = (a[first_id].y - a[second_id].y) * (a[first_id].y - a[second_id].y);
	ans = x+y;
	
	return sqrt(ans);
}











//Grade report(different order)
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
						else if(va->ID < vb->ID) return -1;
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
	
	if(va->total < vb->total) return 1;
	else if(va->total > vb->total) return -1;
	else{
		if(va->Chinese < vb->Chinese) return 1;
		else if(va->Chinese > vb->Chinese) return -1;
		else{
			if(va->English < vb->English) return 1;
			else if(va->English > vb->English) return -1;
			else{
				if(va->math < vb->math) return 1;
				else if(va->math > vb->math) return -1;
				else{
					if(va->science < vb->science) return 1;
					else if(va->science > vb->science) return -1;
					else{
						if(va->ID < vb->ID) return 1;
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
		gList[i].total = gList[i].Chinese + gList[i].English + gList[i].math + gList[i].science;
	}
	
	if( order[0]=='a' ){
		qsort(gList,n,sizeof(Grade),cmp_a);
	}
	else{
		qsort(gList,n,sizeof(Grade),cmp_d);
	}
}
















