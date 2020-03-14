#include <stdio.h>
#include <stdlib.h>
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
	Point * array;
	array = (Point *)malloc(length * sizeof(Point));
	
	int i;
	for(i=0;i<length;i++){
		scanf("%d%d",&array[i].x,&array[i].y);
	}	
	return array;
}

float compute_distance(Point* a, int first_id, int second_id)
{
	float x,y,sum;
	
	x = (a[first_id].x - a[second_id].x) * (a[first_id].x - a[second_id].x);
	y = (a[first_id].y - a[second_id].y) * (a[first_id].y - a[second_id].y);
	
	sum = x+y;
	sum = sqrt(sum);
	return sum;
}
