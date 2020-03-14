//Time Limit Exceed

#include <stdio.h>
int main(void)
{
	int T;
	int t,i,j;
	int L,R;
	int count=0,ans;
	int max=0;
	scanf("%d",&T);
	for(t=0;t<T;t++){
		scanf("%d%d",&L,&R);
		max = 0;			//point : ­n°O±oÂk¹s 
		for(i=L;i<=R;i++){
			count = 0;
			
			for(j=1;j*j<=i;j++){
				//if(j*j==i) count++;
				//else{
				//	if(i%j == 0) count += 2;
				//}
				if(i%j==0){
					if(j*j==i) count = count+1;
					else count = count+2;
				}
			}
			if(count>max){
				max = count;
				ans = i;
			} 
		}
		printf("%d\n",ans);
		
	}
	return 0;
}
