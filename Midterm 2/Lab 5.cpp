// Fire!!!!!!!
#include <stdio.h>

char map[1001][1001];
int m,n;
int x,y;
int flag = 0;		// point
void check(int i,int j);

int main(void)
{
	int i,j;
	//int ans=0;
	scanf("%d%d",&m,&n);
	
	for(i=0;i<m;i++){
		while(getchar() != '\n');		// point
		for(j=0;j<n;j++){
			scanf("%c",&map[i][j]);
			if(map[i][j]=='e'){
				x = i;
				y = j;
			}
		}
	}
	check(x,y);
	
	if(flag == 1) printf("Alive!\n");
	else printf("Dead!\n");
	
	return 0;
}

void check(int i,int j)
{
	if(i>=0 && i<m && j>=0 && j<n && map[i][j] != '^' && flag==0){		//point
		if(map[i][j] == '~') flag = 1;
		//else if(map[i][j] == '.'){
		else{ 
			map[i][j] = '^';
			check(i+1,j);
			check(i,j+1);
			check(i-1,j);
			check(i,j-1);
		}
	}
}




// pC - Ponds
#include <stdio.h>

char map[1001][1001];
int m,n;

void check(int i,int j);

int main(void)
{
	int i,j;
	int count=0;
	scanf("%d%d",&m,&n);
	
	for(i=0;i<m;i++){
		while(getchar() != '\n');
		for(j=0;j<n;j++){
			scanf("%c",&map[i][j]);
		}
	}
	
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			if(map[i][j] == '~'){
				check(i,j);
				count++;
			}
		}
	}
	
	printf("%d\n",count);
	
	return 0;
}

void check(int i,int j)
{
	if(i>=0 && i<m && j>=0 && j<n){
		if(map[i][j] == '~'){
			map[i][j] = '.';
			check(i+1,j);
			check(i,j+1);
			check(i-1,j);
			check(i,j-1);
		}
	}
}






// more simple exercise of pointer on array

#include <stdio.h>
#include "function.h"
void array_exchanger(int* array_a, int* array_b, int length) {
     // your code
     int tmp;
     int i;
     for(i=0;i<length;i++){
     	tmp = * (array_a + i);
     	* (array_a + i) = *(array_b + i);
     	* (array_b + i) = tmp; 
	 }
}















