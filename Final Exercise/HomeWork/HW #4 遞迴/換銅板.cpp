#include <stdio.h>

int nv;
int money;
int value[10];
int number[10];

void show(int nv);
void change(int amount, int index , int nv);

//nv : 有幾種銅板 
//value[] : 幣值 
//money : 總額
 
int main(void)
{
	int i;
	scanf("%d",&nv);
	for(i=0;i<nv;i++){
		scanf("%d",&value[i]);
	}
	scanf("%d",&money);
	
	change(money,0,nv);
	
	
	return 0;
}

void show(int nv)
{
	int i;
	printf("(%d,",number[0]);
	for(i=1;i<nv-1;i++) printf("%d,",number[i]);
	printf("%d)\n",number[nv-1]);
}


void change(int amount,int index,int nv)
{
	if(index < nv){
		if(amount == 0){
			show(nv);
		}
		else if(amount > 0){
			change(amount, index+1,nv);
			
			number[index]++;
			change(amount-value[index],index,nv);
			number[index]--;
		}
		
		
	}
}


