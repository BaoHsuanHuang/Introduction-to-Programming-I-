#include <stdio.h>
#include <string.h>

int main(void)
{
	int T;
	char str1[101];
	char str2[101];
	char tmp;
	int len;
	int flag=0;
	int i,j;
	scanf("%d",&T);
	
	while(T--){
		scanf("%s%s",str1,str2);
		
		len = strlen(str1);
		flag = 0;
		
		for(i=0;i<len;i++){
			for(j=0;j<len;j++){
				if(str1[j]!=str2[j]){
					tmp = str1[0];
					strcpy(str1,str1+1);
					str1[len-1] = tmp;
					break;			//point
				}else{
					if(str1[j]==str2[j] && j==len-1) flag = 1;
				}	
			}
			if(flag==1) break;
		}
		if(flag==1) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
