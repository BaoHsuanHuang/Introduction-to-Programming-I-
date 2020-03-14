/*#include <stdio.h>
int main(void)
{
	int N,n=0;
	int i,j;
	double str[4],goal;
	double str2[2] = {1.0,0.0};
	double new0,new1;
	
	//scanf("%d",&N);
	
	//for(i=1;i<=N;i++){
		for(j=0;j<4;j++){
			scanf("%lf",&str[j]);
		}
		scanf("%lf",&goal);
		new0 = 1.0;
		new1 = 0.0;
		if(new0 > goal){
		new0 = str[0]*str2[0] + str[1]*str2[1];
		new1 = str[2]*str2[0] + str[3]*str2[1];
		str2[0] = new0;
		str2[1] = new1;
		n = n+1;
		}
		printf("%d",n);
		return 0;
	//}
}
*/

#include <stdio.h>
int main(void)
{
    int N,n=0;
    int i,j;
    double str[10][5],goal[10];
    double str2[2] = {1.0,0.0};
    double new0,new1;

    scanf("%d",&N);

    for(i=0;i<N;i++){
    	for(j=0; j<5; j++) {
        	scanf("%lf",&str[i][j]);
        	goal[i] = str[i][4];
   		}
   }
    
    for(i=0;i<N;i++){
    	str2[0] = 1.0;
    	str2[1] = 0.0;
		new0 = str2[0];
    	
    	n=0;
    	while(new0 > goal[i]) {
        	new0 = str[i][0]*str2[0] + str[i][1]*str2[1];
        	new1 = str[i][2]*str2[0] + str[i][3]*str2[1];
        	str2[0] = new0;
        	str2[1] = new1;
        	n = n+1;
    	}
    	printf("%d\n",n);
	}
    return 0;
}

/*#include <stdio.h>
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        double mar[4], goal, ori[2] = {1.0,0.0};
        int ans = 0;
        for(int i = 0;i<4;i++) scanf("%lf", &mar[i]);
        scanf("%lf", &goal);
        while( goal < ori[0] ){
            double now0 = ori[0], now1 = ori[1];
            ori[0] = now0 * mar[0] + now1 * mar[1];
            ori[1] = now0 * mar[2] + now1 * mar[3];
            ans++;
        }
        printf("%d\n", ans);
    }
}*/
