#include <stdio.h>
int gcd(int a,int b);
int main(){
  int a,b;
  printf("Enter a:");
  scanf("%d",&a);
  printf("Enter b:");
  scanf("%d",&b);
  int g=gcd(a,b);
  printf("%d",g);
  return 0;
}

int gcd(int a,int b){
    while(b>0){
        int temp=a%b;
        a=b;
        b=temp;
    }
    return a;
}
