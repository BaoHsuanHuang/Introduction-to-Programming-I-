#include<stdio.h>
int main(void)
{
	int T,L,R;
	int i,j,k,x=0,num=0,ans;
	scanf("%d",&T);
	
	for(i=0;i<T;i++){
		scanf("%d%d",&L,&R);
		x = 0;
		for(j=L;j<=R;j++){
			num=0;
			
			for(k=1;k*k<=j;k++){
				if(j%k == 0){
					if(k*k == j){
						num = num+1;
					}
					else{
						num = num+2;
					}
				}	
			if(num>x){
				x = num;
				ans = j;
			}
			}
		}
		printf("%d\n",ans);
	}
	return 0;	
}

/*#include <stdio.h>
int main(void)
{
	int T,L,R;
	int str[100],str2[50];
	int i,j,k,l,max = str2[j];
	int n=0;
	
	scanf("%d",&T);
	
	for(i=1;i<=T;i++){
		scanf("%d%d",&L,&R);
	}
	
		for(j=L;j<=R;j++){
			for(k=1;k<=j;k++){
				if(j%k == 0){
					str[n] = k;
					printf("%d ",str[n]);
					n++;
					//if(str[n] == 1){
					//	printf("\n");
				}
			}
		}
			

	return 0;
}*/

/*#include <stdio.h>
int main(void)
{
	int T,L,R;
	int i,j,k,num=0,x=0,m=0;
	int str[100];
	
	scanf("%d\n",&T);
	
	for(i=0;i<T;i++){
		
		scanf("%d%d",&L,&R);
		
		for(j=L;j<=R;j++){ 
			num=0;
			for(k=1;k<=j;k++){
				if(j%k == 0){
					num = num+1;
				}
			}
			if(num>x){
				x = num;
			}
			printf("%d",j);
		}
		
		
	}	

	
	return 0;
}
*/

/*#include<stdio.h>
int main(void)
{
    int T,L,R,i,x,a[100];
    scanf("%d\n",&T);
    for(i=1;i<=T;i++)
    {
        scanf("%d %d",&L,&R);
        if(L==R)
            a[i]=L;
        int y=0;
        for(L;L<=R;L++)
        {
            int r=0;
            for(x=1;x*x<=L;x++)
            {
                if(L%x==0)
                {
                    if(L/x==x)
                        r=r+1;
                    else
                        r=r+2;
                }

             }
             if(r>y)
                {
                    y=r;
                    a[i]=L;
                }
         }
    }
    for(i=1;i<=T;i++)
    {
        printf("%d\n",a[i]);
    }
    return 0;
}
*/

/*#include<stdio.h>
int main(void)
{
	int T,L,R;
	int i,j,k,x=0,num=0,ans;
	scanf("%d",&T);
	
	for(i=0;i<T;i++){
		scanf("%d%d",&L,&R);
		
		for(j=L;j<=R;j++){
			num=0;
			for(k=1;k*k<j;k++){
				if(j%k == 0){
					num = num+1;
				}				
				num = num*2;
			}
			if(k*k == j) {
					num = num+1;
			}	
				
			if(num>x){
				x = num;
				ans = j;
			}
		}
		printf("%d\n",ans);
		
	}
	return 0;	
}*/
