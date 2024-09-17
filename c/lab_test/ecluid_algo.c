#include <stdio.h>
int gcd(int a,int b){
  if(b==0) return a;
  return gcd(b,a/b);
}
int main(){
  int x=45;
  int y=18;
  int GCD = gcd(x,y);
  printf("The gcd of %d and %d is %d ",x,y,GCD);
}
