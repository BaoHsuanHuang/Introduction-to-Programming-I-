#include <stdio.h>
#include <string.h>

int main(void)
{
	int n;
	int i,j;
	int len;
	char dir[101];
	int count[4]={0};
	int map[2][100];
	scanf("%d",&n);
	
	for(i=0;i<n;i++){		//總共要輸n次路徑 
		scanf("%s",dir);
		len = strlen(dir);
		
		for(j=0;j<len;j++){
			if(dir[j]=='N') count[0]++; //北 0 
			else if(dir[j]=='S') count[1]++;	//南 1
			else if(dir[j]=='E') count[2]++;	//東 2
			else count[3]++; 
		}
		
		y = count[0]-count[1];		//y軸 
		x = count[2]-count[3];		//x軸 
		
		map[0][i] = y;
		map[1][i] = x;
	}
	for(i=0;i<n;i++){
		if()
	}
	
	return 0;
}
