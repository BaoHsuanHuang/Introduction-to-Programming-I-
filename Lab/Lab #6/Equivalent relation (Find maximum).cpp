#include <stdio.h>
//#include "function.h"

#define SIZE 100

void execInst(int *ptrArr[], char inst, int param1, int param2);
int findMax(int *ptrArr[], int start, int end);


int main() {
	int *ptrArr[SIZE]; // «ü¼Ð°}¦C 
	int dataArr[SIZE] = {0};
	char inst;
	int dataNum, instNum;
	int param1, param2;
	int start, end;
	int i;

	/* input */
	scanf("%d %d", &dataNum, &instNum);

	/* initialize the ptrArr */
	for (i = 0; i < dataNum; i++)
		ptrArr[i] = &dataArr[i];

	for (i = 0; i < instNum; i++) {
		scanf(" %c %d %d", &inst, &param1, &param2);
		execInst(ptrArr, inst, param1, param2);
	}
    scanf("%d %d", &start, &end);
	/* output */
	for (i = 0; i < dataNum - 1; i++) {
		printf("%d ", dataArr[i]);
	}
	printf("%d\n", dataArr[i]);
	for (i = 0; i < dataNum - 1; i++) {
		printf("%d ", *ptrArr[i]);
	}
	printf("%d\n", *ptrArr[i]);


	printf("%d\n", findMax(ptrArr , start, end));

	return 0;
}

void execInst(int *ptrArr[], char inst, int param1, int param2)
{
	if(inst == 'S'){
		*ptrArr[param1] = param2;
	}else if(inst == 'M'){
		*ptrArr[param1] = *ptrArr[param1] * param2;
	}else if(inst == 'P'){
		ptrArr[param1] = ptrArr[param2];
	}
}

int findMax(int *ptrArr[], int start, int end)
{
	int i;
	int ans;
	ans = *ptrArr[start];
	for(i=start;i<=end;i++){
		if(*ptrArr[i] > ans){
			ans = *ptrArr[i];
		}
	}
	return ans;
}




