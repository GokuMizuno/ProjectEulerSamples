#include <iostream.h>
i=j=0;g=20;
void main(){
   long R[g][g];
   while(i<g){
       R[i][j] = 1;
	   R[j][i] = R[i][j];
       i++;}
   i=1;
   while(i<g){
       j=1;
       while(j<g){
           R[i][j] = R[i-1][j] + R[i][j-1];
           j++;}
       i++;}
   printf("%d", R[g-1][g-1]);
}
