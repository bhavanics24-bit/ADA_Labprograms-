#include <stdio.h>

int main(){
    int low, mid, high;

    printf("Enter low: ");
    scanf("%d",&low);

    printf("Enter mid: ");
    scanf("%d",&mid);

    printf("Enter high: ");
    scanf("%d",&high);

    int a[100], b[100];

    printf("Enter %d sorted elements:\n", high+1);
    for(int i=low;i<=high;i++){
        scanf("%d",&a[i]);
    }

    int i = low;
    int j = mid + 1;
    int k = low;

    while(i<=mid && j<=high){
        if(a[i] <= a[j]){
            b[k] = a[i];
            i++;
        }
        else{
            b[k] = a[j];
            j++;
        }
        k++;
    }

    while(i<=mid){
        b[k] = a[i];
        i++;
        k++;
    }

    while(j<=high){
        b[k] = a[j];
        j++;
        k++;
    }

    printf("Merged array:\n");
    for(k=low;k<=high;k++){
        printf("%d ", b[k]);
    }

    return 0;
}




