#include <stdio.h>
#include <string.h>
int main(void){
 int n,strlen_str,strlen_A,B,i;
 char str[100],A[100],Bi[100];
 scanf("%s\n%d\n",A,&n);
 strlen_A=strlen(A);
 for(B=1;B<=n;B++){
  int n_Bi=0;
  scanf("%s",str);
  strlen_str=strlen(str);
  for(i=0;i<=(strlen_str-strlen_A);i++){
   int strlen=0;
   int j=i,k=0;
   while(str[j]==A[k]&&strlen<strlen_A){
    j++;
    k++;
    strlen++;
   }
   if(strlen==strlen_A)
   n_Bi++;
  }
  Bi[B]=n_Bi;
 }
 
 int ans=Bi[1],h;
 for(h=1;h<=n;h++){
  if(ans<Bi[h])
  ans=Bi[h];
 }
 
 printf("%d",ans);
}
