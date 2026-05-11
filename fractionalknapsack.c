#include<stdio.h>
#include<time.h>
struct Item{
    int weight;
    int profit;
    float ratio;
};
void sort(struct Item items[], int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(items[i].ratio < items[j].ratio){
                struct Item temp=items[i];
                items[i]=items[j];
                items[j]=temp;
            }
        }
    }
}
float fractionalKnapsack(int cap,struct Item items[], int n){
    int remcap=cap;
    float mincost=0.0;
    for(int i=0;i<n;i++){
        if(remcap >= items[i].weight){
            remcap-=items[i].weight;
            mincost+=items[i].profit;
        }
        else{
            mincost=mincost + (items[i].ratio * remcap);
            break;
        }
    }
    return mincost;
}
int main(){
    int n, cap;
    clock_t start,end;
    printf("Enter the number of items: ");
    scanf("%d",&n);
    struct Item items[n];
    printf("Enter the weight and profit of all the items: ");
    for(int i=0;i<n;i++){
        scanf("%d %d",&items[i].weight,&items[i].profit);
        items[i].ratio=(float)items[i].profit/items[i].weight;
    }
    printf("Enter the capacity of the Knapsack: ");
    scanf("%d",&cap);
    start=clock();
    sort(items,n);
    float cost=fractionalKnapsack(cap,items,n);
    end=clock();
    printf("The Optimal Solution is: %.2f",cost);
    double time_taken=(double)(end-start)*10000/CLOCKS_PER_SEC;
    printf("\nExecution time: %f seconds",time_taken);
    return 0;
}
