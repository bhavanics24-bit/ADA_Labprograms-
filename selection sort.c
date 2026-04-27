#include <stdio.h>
#include <time.h>

void selectionSort(int a[], int n)
{
    int i,j,min,temp;

    for(i=0;i<n-1;i++)
    {
        min=i;

        for(j=i+1;j<n;j++)
        {
            if(a[j]<a[min])
                min=j;
        }

        temp=a[i];
        a[i]=a[min];
        a[min]=temp;
    }
}

int main()
{
    int a[100],n,i;
    clock_t start,end;
    double time_taken;

    printf("Enter number of elements: ");
    scanf("%d",&n);

    printf("Enter elements:\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);

    start = clock();

    selectionSort(a,n);

    end = clock();

    printf("Sorted array:\n");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);

    time_taken = (double)(end-start)/CLOCKS_PER_SEC;

    printf("\nExecution time = %f seconds",time_taken);

    return 0;
}
