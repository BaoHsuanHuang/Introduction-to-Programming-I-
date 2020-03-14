//  Binary representation

#include <stdio.h>

int input;
void binary(int input);

int main(void)
{
	scanf("%d",&input);
	
	binary(input);
	
	return 0;
}

void binary(int input)
{
	if(input>0){
		binary(input/2);
		printf("%d",input%2);
	}
	//printf("%d",input%2);
}
