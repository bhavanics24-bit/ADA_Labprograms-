#include<stdio.h>
#include<time.h>

int max(int a,int b)
{
    return (a>b)?a:b;
}

int knapsack(int n,int m,int W[],int P[])
{
    int Table[n+1][m+1];
    for(int i=0;i<=n;i++){
        Table[i][0]=0;
    }
    for(int j=0;j<=m;j++){
        Table[0][j]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(j<W[i-1])
                Table[i][j]=Table[i-1][j];
            else
                Table[i][j]=max(Table[i-1][j],P[i-1]+Table[i-1][j-W[i-1]]);
        }
    }
    return Table[n][m];
}

int main()
{
    clock_t start,end;
    int n,m,W[50],P[50],Table[50][50];
    printf("Enter number of items:");
    scanf("%d",&n);
    printf("Enter max weight:");
    scanf("%d",&m);
    printf("enter profits:");
    for(int i=0;i<n;i++){
        scanf("%d",&P[i]);
    }
    printf("enter weights:");
    for(int i=0;i<n;i++){
        scanf("%d",&W[i]);
    }
    start=clock();
    int maxprofit=knapsack(n,m,W,P);
    end=clock();
    float time=(double)(end-start)*1000/CLOCKS_PER_SEC;
    printf("Maximum profit:%d",maxprofit);
    printf("execution time:%f",time);
    return 0;

}
