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
	
	for(i=0;i<n;i++){		//�`�@�n��n�����| 
		scanf("%s",dir);
		len = strlen(dir);
		
		for(j=0;j<len;j++){
			if(dir[j]=='N') count[0]++; //�_ 0 
			else if(dir[j]=='S') count[1]++;	//�n 1
			else if(dir[j]=='E') count[2]++;	//�F 2
			else count[3]++; 
		}
		
		y = count[0]-count[1];		//y�b 
		x = count[2]-count[3];		//x�b 
		
		map[0][i] = y;
		map[1][i] = x;
	}
	for(i=0;i<n;i++){
		if()
	}
	
	return 0;
}
