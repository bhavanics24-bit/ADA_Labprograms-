#include <stdio.h>
int towerofhanoi(int n,char f,char t, char a){
  if(n==0)
    return 0;
  towerofhanoi(n-1,f,a,t);
  printf("Disk %d moved from %c to %c\n",n,f,t);
  towerofhanoi(n-1,a,t,f);
}

int main(){
    int n;
    printf("enter n:");
    scanf("%d",&n);
    towerofhanoi(n,'A','C','B');
    return 0;
}
