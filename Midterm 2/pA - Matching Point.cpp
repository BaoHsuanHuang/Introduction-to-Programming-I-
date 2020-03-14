#include <stdio.h>
#include <string.h>

char a[21],b[21];
int la,lb;
int ans=0;
void check(int i,int j);

int main(void)
{
	while(scanf("%s",a) != EOF && scanf("%s",b) != EOF){
		
		la = strlen(a);
		lb = strlen(b);
		
		check(0,0);
		
		printf("%d\n",ans);
		
		ans = 0;
	}
	return 0;
}

void check(int now,int pos)
{
	int i,j;
	if(pos == lb){
		ans++;
	}
	else{
		for(i=now;i<la;i++){
			if(a[i]==b[pos]){
				check(i+1,pos+1);
			}
		}
	}
}








/*#include <stdio.h>
#include <string.h>
char a[21],b[21];

void check(int j,int i,int la,int lb);

int main(void)
{
	int la,lb;
	int i,j;
	
	while(scanf("%s",a) != EOF && scanf("%s",b) != EOF){
		
			la = strlen(a);
			lb = strlen(b);
			printf("%d  %d\n",la,lb);
			for(j=0 ; j<lb ; j++){
				for(i=0 ; i<la ; i++){
					if(b[j] == a[i]){
						check( j , i , la ,lb);
					}
				}
			}
			
	}
	
	return 0;
}

void check(int y,int x,int la,int lb)
{
	int i,j;
	int count=0,ans=0;
	
	if(i>=x && i<la && j>=y && j<lb){
		if(a[i] == b[j]){
			count++;
			if(count = lb) ans++;
			check(j+1,i+1,la,lb);
			check(j,i+1,la,lb);
		}	
	}
	
	printf("%d\n",ans);
}
*/
