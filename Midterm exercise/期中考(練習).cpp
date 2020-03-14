// (HW 2) Change the Cap
#include <stdio.h>
int main(void)
{
	int N,ans;
	
	scanf("%d",&N);
	
	if(N%3 == 2){
		ans = N/3*2 + 2;
	}else{
		ans = N/3*2 + 1;
	}
	printf("%d\n",ans);
	
	return 0;
} 







// (HW 2)Time conversion
#include <stdio.h>
int main(void)
{
	int N,a,b;
	scanf("%d",&N);
	
	a = N/100;
	b = N%100;
	
	if(a>=12){
		printf("%.2d:%.2d p.m.",a-12,b);
	}else{
		printf("%.2d:%.2d a.m.",a,b);
	}
	return 0;
}







// (HW 2)binary addition
#include <stdio.h>
int main(void)
{
	int N,M,i=0,a,ans=0;
	int A[10];
	
	scanf("%d",&N);
	M = N+1;
	
	while(M>0){
		A[i] = M%2;
		M = M/2;
		i++;
	} 
	a = i-1;
	for(i=i-1;i>=0;i--){
		printf("%d",A[i]);
	}
	
	for(i=0;i<=a;i++){
		if(A[i]==0) ans++;
		else break;
	}
	printf(" %d",ans);
	return 0;
}








// (HW 1)Arithmetic Sequence
#include <stdio.h>
int main(void)
{
	int a,n,d;
	int x,sum;
	
	scanf("%d%d%d",&a,&n,&d);
	
	x = a+(n-1)*d;
	sum = (2*a+(n-1)*d)*n/2;
	
	printf("%d %d",x,sum);
	return 0;
}






// (HW 1)A simple set problem
#include <stdio.h>
int main(void)
{
	int N,x,y,z;
	int a,b;
	
	scanf("%d%d%d%d",&N,&x,&y,&z);
	
	a = x+y+z-N;
	b = x-a;
	
	printf("%d %d",a,b);
	
	return 0;
} 







// (HW 1)Easy Palindrome
#include <stdio.h>
int main(void)
{
	double N,M,sum;
	int a,b,c,d,e,f,x;
	
	scanf("%lf",&N);
	
	x = N*1000;
	a = x/100000;
	b = (x%100000)/10000;
	c = (x%10000)/1000;
	d = (x%1000)/100;
	e = (x%100)/10;
	f = x%10;
	
	M = c*100 + b*10 + a + f*0.1 + e*0.01 + d*0.001;
	sum = N+M;
	
	printf("%.3lf",sum);
	
	return 0;
}








// (Lab 2) lab02_a 
#include <stdio.h>
int main(void)
{
	int a[10];
	int i,ans,k;
	
	for(i=1;i<=9;i++){
		scanf("%d",&a[i]);
	}
	k=1;
	ans = a[k];
	while(a[k] != 1){
		k = a[k];
		ans = ans + a[k];
	}
	
	printf("%d\n",ans);
	return 0;
}






// (Lab 2) lab02_b 
#include <stdio.h>
int main(void)
{
	int N,i,j,n=0;
	float Va=1, Vb=0, p[4], T, c;
	
	scanf("%d",&N);
	for(i=0;i<N;i++){
		n=0;
		Va=1;
		Vb=0;
		
		for(j=1;j<=4;j++){
			scanf("%f",&p[j]);
		}
		scanf("%f",&T);
		
		while(Va > T){
			c = Va;
			Va = Va*p[1] + Vb*p[3];
			Vb = c*p[2] + Vb*p[4];	
			
			n++;	
		}
		printf("%d\n",n);
		
	}
	return 0;
}






// (Lab 3) Alphabet Triangle
#include <stdio.h>
int main(void)
{
	int i,j,ch,a;
	
	ch = getchar();
	a = ch - 'A' + 1;
	
	for(i=1;i<=a;i++){
		
		for(j=a;j>i;j--){
			printf(" ");
		}
		
		for(j='A';j<'A'+i;j++){
			putchar(j);
		}
		
		for(j='A'+ i-2;j>='A';j--){
			putchar(j);
		}
		
		for(j=a;j>i;j--){
			printf(" ");
		} 
		
		printf("\n");
	}
	
	return 0;
}







// (Lab 3) Full House 2018 
#include <stdio.h>
int main(void)
{
	char input[5][3];
	int T,i,j,cards[14]={0};
	
	scanf("%d",&T);
	
	for(i=0;i<T;i++){
		scanf("%s%s%s%s%s",input[0],input[1],input[2],input[3],input[4]);
		//cards[14] = {0};
		
		for(j=1;j<=13;j++){
			cards[j]=0;
		}
		int flag2 = 0;
		int flag3 = 0;
		for(j=0;j<5;j++){
			if(input[j][0] == 'A') cards[1]++;
			else if(input[j][0] == 'J') cards[11]++;
			else if(input[j][0] == 'Q') cards[12]++;
			else if(input[j][0] == 'K') cards[13]++;
			else if(input[j][0] == '1') cards[10]++;
			else cards[input[j][0]-'0']++;
		}
		//printf(" %d\n",cards[2]);
		for(j=1;j<=13;j++){
			if(cards[j]==2) flag2 = 1;
			if(cards[j]==3) flag3 = 1;
		}
		
		if(flag2==1 && flag3==1){
			printf("YES\n");
		}else printf("NO\n");
		
	}
	return 0;
 } 







// (Midterm1_Practice) The number of occurrences
#include <stdio.h>
#include <string.h>
int main(void)
{
	char input[10],str[50];
	int n,i,count=0,flag=0,max=0;
	
	scanf("%s",input);
	scanf("%d",&n);
	
	for(i=0;i<n;i++){
		scanf("%s",str);
		
		int j,k;
		int a,b;
		a = strlen(input);
		b = strlen(str);
		count = 0;
		
		for(j=0;j<=b-a;j++){
			flag = 0;
			for(k=0;k<a;k++){
				if(str[j+k] == input[k]) flag++;
				
			}
			if(flag==a) count++;
		}
		if(count > max) max = count;
		//printf("%d ",count);
		
	}
	printf("%d",max);
	return 0;
}








// (Midterm1_Practice) Progression
#include <stdio.h>
int main(void)
{
	int a,b,c,x,y;
	
	scanf("%d%d%d",&a,&b,&c);
	
	if( a+c == 2*b){
		x = 2*a-b;
		y = 2*c-b;
	}
	
	if(b*b == a*c){
		x = a*a/b;
		y = c*c/b;
	}
	
	printf("%d %d",x,y);
	
	return 0;
}








// (Midterm1_Practice) Simple integer sorting
#include <stdio.h>
int main(void)
{
	int T,n;
	int i;
	int j;
	int k;
	int str[10001];
	scanf("%d",&T);
	
	for(i=0;i<T;i++){
		
		scanf("%d",&n);
		
		for(j=1;j<=n;j++){
			scanf("%d",&str[j]);
		}
		
		for(j=1;j<n;j++){
			
			for(k=j+1;k<=n;k++){
				if(str[j] > str[k]){
					int c;
					c = str[j];
					str[j] = str[k];
					str[k] = c;
				} 
			}
		}
		
		for(j=1;j<n;j++){
			printf("%d ",str[j]);
		}
		printf("%d\n",str[n]);
		
	}
	return 0;
 } 








// (Midterm1_Practice) pA - Arranging a Sequence
#include <stdio.h>
int main(void)
{
	int n,m;
	int input[120000]={0},flag[220000]={0};
	int i,j;
	
	scanf("%d%d",&n,&m);
	
	for(i=m;i>=1;i--){		// point
		scanf("%d",&input[i]);
		flag[input[i]] = 1;
	}
	
	for(i=1;i<=m;i++){
		if(flag[input[i]]==1){
			printf("%d\n",input[i]);
			flag[input[i]] = -1;
		}
	}
	
	for(i=1;i<=n;i++){
		if(flag[i]==0){       // point  
			printf("%d\n",i);
		}
	}
	return 0;
}
#include <stdio.h>
int main(void)
{
	int n,m;
	
	scanf("%d%d",&n,&m);
	< 錯誤解法 >
	int a[250000]={0};
	int i;
	for(i=1;i<=n;i++){
		a[i]=i;
	}
	
	int input[150000]={0};
	int j;
	for(j=1;j<=m;j++){
		scanf("%d",&input[j]);
		a[input[j]]=0;
	}
	
	for(j=m;j>=1;j--){
		printf("%d\n",input[j]);
	}
	for(i=1;i<=n;i++){
		if(a[i] != 0) printf("%d\n",a[i]);
	}
	
	return 0;
} 

// point : input 陣列裡的字可能重覆 











// (Midterm1_Practice) pE - Exquisite Substrings
#include <stdio.h>
#include <string.h>
int main(void)
{
	char str[2500]={0};
	int length;
	
	while(scanf("%s",str) != EOF){
		length = strlen(str);
		int i;
		int count=0;
		for(i=0;i<length;i++){
			int j,k;
			
			for(j=i-1,k=i+1 ; j>=0 && k<length ; j--,k++){
				if(str[j]==str[k]) count++;
				else break;		// point 
			}
			for(j=i,k=i+1 ; j>=0 && k<length ; j--,k++){
				if(str[j]==str[k]) count++;
				else break;		// point
			}	
		}
		printf("%d\n",count);
	}
	return 0;
} 
 

// (Yang_hw3) Longest Palindrome substring
#include <stdio.h>
#include <string.h>
int main(void)
{
	int T;
	int i,length,c;
	char str[10001];
	
	scanf("%d",&T);
	for(i=0;i<T;i++){
		
		int max=1;
		int count =0;
		scanf("%s",str);
		length = strlen(str);
		
		for(c=0;c<length;c++){
			int j,k;
			count=0;   // point
			for(j=c-1,k=c+1 ; j>=0 && k<length ; j--,k++){
				if(str[j]==str[k]) count = count+2;
				else break;
				if(count+1>max){
					//count = count+1;
					max = count+1;
				}
			}
			count = 0;
			for(j=c,k=c+1 ; j>=0 && k<length ; j--,k++){
				if(str[j]==str[k]) count = count+2;
				else break;
				if(count > max) max = count;
			}
		}
		printf("%d\n",max);
	}
	return 0;
}









// (Midterm1_Practice) pB - Birthday Party
#include <stdio.h>
long long int gcd(long long int n,long long int x);

int main(void)
{
	long long int T,n,x1,x2,x3;
	long long int i,a,b,c;
	
	scanf("%lld",&T);
	for(i=0;i<T;i++){
		
		scanf("%lld%lld%lld%lld",&n,&x1,&x2,&x3);
		a = gcd(n,x1);
		b = gcd(n,x2);
		c = gcd(n,x3);
		// 找a b c 的最小公倍數 ， 先找a b 的最小公倍數
		long long int lcm1,lcm2,gcd_ab,gcd_c;
		gcd_ab = gcd(a,b);
		lcm1 =  (a/gcd_ab)*b;
		gcd_c = gcd(lcm1,c);
		lcm2 = (lcm1/gcd_c)*c;
		
		long long int ans;
		ans = n/lcm2;		// point
		printf("%lld\n",ans);
	}
	return 0;
}

long long int gcd(long long int n,long long int x)		// point
{	
	if(x==0) return n;
	else return gcd(x,n%x);
}










// (Midterm1_Practice) pD - Distrait 
#include <stdio.h>
int main(void)
{
	int map,pos[51][2]={0},row[5]={0},col[5]={0};
	int i,j;
	
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			scanf("%d",&map);
			pos[map][0] = i;
			pos[map][1] = j;
		}
	}
	
	int T,N;
	int input,a,b,line1=0,line2=0,k,l,flag=0;
	scanf("%d",&T);
	for(k=0;k<T;k++){
		scanf("%d",&N);
		
		for(i=0;i<5;i++){
			row[i] = 0;
			col[i] = 0;
			flag = 0;
			line1 = 0;
			line2 = 0;
		}
		
		for(l=0;l<N;l++){		
			scanf("%d",&input);
			
			a = pos[input][0];
			b = pos[input][1];
			row[a]++;
			col[b]++;
			
			if(a==b) line1++;
			if(a+b==4) line2++;
		
			if(row[0]==5 || row[1]==5 || row[2]==5 || row[3]==5 || row[4]==5 || 
			col[0]==5 || col[1]==5 || col[2]==5 || col[3]==5 || col[4]==5 || 
			line1==5 || line2==5){
				printf("Case #%d: %d\n",k+1,l+1);
				flag = 1;		// point
				break;		//point
			}
		}
		for(l=l+1;l<N;l++){
			scanf("%d",&input);
		}
		if(flag == 0){
			printf("Case #%d: Not yet \\(^o^)/\n",k+1);
		}
	}
	return 0;
}










// (HW 3) Factor Counter
< 錯誤解法 : 超時 > 
#include <stdio.h>
int main(void)
{
	int T,a,b;
	int i;
	
	scanf("%d",&T);
	
	for(i=0;i<T;i++){
		scanf("%d%d",&a,&b);
		
		int j,k,ans;
		int count=0,max=0;
		for(j=a;j<=b;j++){
			count = 0;
			for(k=1;k<=j;k++){
				if(j%k==0) count++;
			}
			//printf("%d\n",count);
			if(count>max){
				max = count;
				ans = j;
			}
			//for(m=1;m<=b-a+1;m++){
			//	str[m] = count;
			//}	
		}
		printf("%d\n",ans);
	}
	return 0;
}

#include <stdio.h>
int main(void)
{
	int T,a,b;
	int i,j,k,ans;
	
	scanf("%d",&T);
	for(i=0;i<T;i++){
		scanf("%d%d",&a,&b);
		
		int max=0;
		for(j=a;j<=b;j++){
			int count = 0;
			for(k=1;k*k<=j;k++){
				if(j%k==0 && k*k<j) count = count+2;
				if(k*k==j) count = count+1; 
			}
			if(count > max){
				max = count;
				ans = j;
			}
			
		}
		printf("%d\n",ans);		
	}
	return 0;
 } 









// (HW 3) Hexadecimal to Binary
#include <stdio.h>
int main(void)
{
	int x,y;
	
	scanf("%x%x",&x,&y);
	
	int a,b,c;
	a = (int)x;
	b = (int)y;
	c = a+b;
	
	int i=0,str[100];
	while(c>1){
		str[i] = c%2;
		c = c/2;
		i++;
	}
	if(c==1) str[i] = c;
	
	for(;i>=0;i--){
		printf("%d",str[i]);
	}
	
	return 0;
}








// (Midterm1_Practice) pC - Collinear
#include <stdio.h>
int main(void)
{
	int T,n,x[150]={0},y[150]={0},point[150]={0};
	int i,j,a,b,c;
	float dx,dy,m1,m2;
	
	scanf("%d",&T);
	for(i=0;i<T;i++){
		scanf("%d",&n);
		
		for(j=0;j<n;j++){
			scanf("%d%d",&x[j],&y[j]);
		}
		
		for(a=0;a<n;a++){
			int flag=0;
			for(b=a+1;b<n;b++){
				dx = x[b]-x[a];
				dy = y[b]-y[a];
				m1 = dy/dx;
				if(dx == 0) flag=1;
				
				int count = 2;
				for(c=0;c<n;c++){
					if(c==a || c==b) continue;
					else{
						dx = x[c]-x[a];
						dy = y[c]-y[a];
						m2 = dy/dx;
						if(flag==1 && x[c]==x[a]) count++;
						else {
							if(m1==m2) count++;
						}
					}
				}
				point[count]++;
				count = 2;
				flag = 0;
			}
		}
		int k,ans=0;
		for(k=3,ans=0;k<101;k++){
			ans = ans + point[k] * 2 / k / (k - 1) ;     // point
			point[k] = 0;
		}
		printf("%d\n", ans);
	}
	return 0;
}









// (HW 3) EECS_MID1_1
#include <stdio.h>
#include <string.h>

#define EAST 0
#define SOUTH 1
#define WEST 2
#define NORTH 3

char map[100][100];
char actions[100]={};
int coin_amount = 0;

// tank's initial direction
char init_dir;
// tank's direction now
int dir_now;
// tank's center x and y
int center_x, center_y;

void decide_initial_direction()
{
    /// Decide tank's initial direction
    /// Using init_dir
    /// To determine dir_now
    
    if(init_dir == 'N') dir_now = 3;
    else if(init_dir == 'E') dir_now = 0;
    else if(init_dir == 'S') dir_now = 1;
    else dir_now = 2;
}

void take_a_step()
{
    if (dir_now == 3){
        /// Detect wall first
        if (map[center_x-2][center_y-1] == '#' || map[center_x-2][center_y] == '#'
		|| map[center_x-2][center_y+1] == '#') return;
        /// And then detect hill
        else if (map[center_x-2][center_y-1] == '^' || map[center_x-2][center_y] == '^' 
		|| map[center_x-2][center_y+1] == '^') return;
        /// If there is no obstacle, take a step
        else {
			// 錯 : map[center_x-1][center_y];
			center_x = center_x - 1;
        }
    }
    else if (dir_now == 1){
		if (map[center_x+2][center_y-1] == '#' || map[center_x+2][center_y] == '#'
		|| map[center_x+2][center_y+1] == '#') return;
		
		else if (map[center_x+2][center_y-1] == '^' || map[center_x+2][center_y] == '^' 
		|| map[center_x+2][center_y-1] == '^') return;
		
		else {
			center_x = center_x + 1;
        }
    }
    else if (dir_now == 0){
		if (map[center_x-1][center_y+2] == '#' || map[center_x][center_y+2] == '#'
		|| map[center_x+1][center_y+2] == '#') return;
		
		else if (map[center_x-1][center_y+2] == '^' || map[center_x][center_y+2] == '^' 
		|| map[center_x+1][center_y+2] == '^') return;
		
		else {
			center_y = center_y + 1;
    	}
	}
    else if (dir_now == 2){
		if (map[center_x-1][center_y-2] == '#' || map[center_x][center_y-2] == '#'
		|| map[center_x+1][center_y-2] == '#') return;
		
		else if (map[center_x-1][center_y-2] == '^' || map[center_x][center_y-2] == '^' 
		|| map[center_x+1][center_y-2] == '^') return;
		
		else {
			center_y = center_y + 1;
   		}
    }
}

void pick_the_coins()
{
    int j, k;
    //coin_amount = 0;
    for (j = center_x - 1; j <= center_x + 1; j++){
        for (k = center_y - 1; k <= center_y + 1; k++){
            /// determine whether there are coins under the tank
			if(map[j][k]=='$'){
				coin_amount++;
				map[j][k] = '=';
			}
        }
    }
}

void turn_right()
{
    /// Change direction depending on dir_now
    dir_now = (dir_now + 1)%4;
}

 

void turn_left()
{
    /// Change direction depending on dir_now
    dir_now = (dir_now+3)%4;
}

int main()
{
    int i, j, k, rows, cols;
    int actions_number;
    int component = 0;

    /// Raed problem's input
    scanf("%d %d %d %c", &rows, &cols, &actions_number, &init_dir);
    while (getchar() != '\n');
    for (i = 0; i < actions_number; i++){
        scanf("%c", &actions[i]);
    }

    /// Read map
    for (i = 1; i <= rows; i++){
        while (getchar() != '\n');
        for (j = 1; j <= cols; j++){
            scanf("%c", &map[i][j]);
            /// Find tank's center x and y
            if (((map[i][j]) == 'x') || ((map[i][j]) == 'o') || ((map[i][j]) == 'O')){
                component++;
                if (component == 5){
                    center_x = i;
                    center_y = j;
                }
            }
        }
    }

    decide_initial_direction();

    for (i = 0; i < actions_number; i++){
        if (actions[i] == 'F'){
            take_a_step();
            pick_the_coins();
        }
        else{
            if (actions[i] == 'R'){
                turn_right();
            }
            if (actions[i] == 'L'){
                turn_left();
            }
        }
    }

    printf("%d\n", coin_amount);

    return 0;
}















