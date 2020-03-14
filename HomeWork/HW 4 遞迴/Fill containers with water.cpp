#include <stdio.h>
#define MAXNV 5
int DONE = 0;
int liters[MAXNV];
int numbers[MAXNV];

void show(int nv);
void filling(int amount, int cur, int nv);

int j=0;
int water;
int min=100;
int min_numbers[MAXNV]={0};

int main(void)
{
    int nv, i;

    scanf("%d", &nv);	// 有nv種容器 
    for (i=0; i<nv; i++) {
        scanf("%d", &liters[i]);	// liters陣列為容器的陣列 
    }
    scanf("%d", &water);	// water 為總公升數 
    filling(water, 0, nv);	// 0 代表從 litters[0] 開始 

    for(i=0;i<nv;i++)
        numbers[i]=min_numbers[i];	// 把 min_numbers陣列存進 numbers陣列 
    show(nv);
    return 0;
}

void show(int nv)
{
    int i;
    printf("(%d", numbers[0]);
    for (i=1; i<nv; i++) {
        printf(",%d", numbers[i]);
    }
    printf(")\n");
}
int count=0, i;
void filling(int amount, int cur, int nv)
{
    /* your code */
    
    if(cur < nv){
    	if(amount == 0){
    		count = 0;
    		for(i=0 ;i<nv ;i++){
    			count += numbers[i];
			}
			if(count < min){
				min = count;
				for(i=0;i<nv;i++){
					min_numbers[i] = numbers[i];
				}
			}
    		
		}else if(amount > 0){
			
			filling(amount,cur+1,nv);
			numbers[cur]++;
			
	    	filling(amount-liters[cur], cur, nv);
			numbers[cur]--;
	    	
		}
	}
} 

