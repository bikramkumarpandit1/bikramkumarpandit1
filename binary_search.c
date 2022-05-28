#include <stdio.h>

void binary_search(int arr[],int size)
{
    int low=0,high=size-1,x,z,flag=0;
    printf("Which element you want to search: ");
    scanf("%d",&x);
    for(int i=0;i<size;i++)
    {
        z=(low+high)/2;
        if(x==arr[z])
        {
            printf("%d found in %d number of comparisons ",x,i);
            flag=1;
            break;
        }
        else if(x<arr[z])
        {
            high=z-1;
        }
        else if(x>arr[z])
        {
            low=z+1;
        }
    }
    if(flag==0)
    {
        printf("%d not found in the array",x);
    }
}

int main()
{
    int n;
    printf("How many data you want to stored in array: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the data in ascending order: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    binary_search(arr,n);
}