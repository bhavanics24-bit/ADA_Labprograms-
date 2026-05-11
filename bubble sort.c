#include <stdio.h>
#include <time.h>

void bubbleSort(int a[], int n)
{
    int i,j,temp;

    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(a[j] > a[j+1])
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
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

    bubbleSort(a,n);

    end = clock();

    printf("Sorted array:\n");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);

    time_taken = (double)(end-start)/CLOCKS_PER_SEC;

    printf("\nExecution time = %f seconds",time_taken);

    return 0;
}
