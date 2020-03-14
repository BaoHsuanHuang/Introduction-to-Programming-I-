#include <stdio.h>
#define map_size 15
#define car_size 3

int map[map_size][map_size];
void map_reset(void);
void map_show(void);

int blocks[map_size][map_size];
void blocks_read(void);
void blocks_on_map(void);

int money[map_size][map_size];
void money_read(void);
void money_on_map(void);


int main(void)
{
	blocks_read();
	map_reset();
	blocks_on_map();
	map_show();
	
	return 0;
}


void map_reset(void)
{
	int i,j;
	
	for(i=0;i<map_size;i++){
		for(j=0;j<map_size;j++){
			map[i][j] = '.'; //point
		}
	}
	for(i=0;i<map_size;i++){
		for(j=0;j<map_size;j++){
			map[0][j] = map[i][0] = map[i][map_size-1] = map[map_size-1][j] = 'H';//point
		}
	}
}
void map_show(void)
{
	int i,j;
	for(i=0;i<map_size;i++){
		for(j=0;j<map_size;j++){
			putchar(map[i][j]); //point
		}
		putchar('\n'); //point
	}
}

void blocks_read(void)
{
	int N,r,c,i,k;
	int blocks[10][2];
	
	scanf("%d",&N);
	
	for(i=0;i<N;i++){
		for(k=0;k<2;k++){
			scanf("%d",&r);
			blocks[i][k] = 1;
		}
	}
}
void blocks_on_map(void)
{
	int i,j;
	
	for(i=0;i<map_size;i++){
		for(j=0;j<map_size;j++){
			if(blocks[i][j] == 1){
				map[i][j] = '#';
			}
		}
	}
}













