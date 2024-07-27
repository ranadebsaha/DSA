#include<stdio.h>
void quicksort(int[],int, int);
int partition(int[],int,int);
void swap(int*,int*);
void main(){
    int n,i;
    printf("Enter array Size: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter array elements one by one: ");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("\nBefore Sorting: ");
    for(i=0;i<n;i++){
        printf("%d  ",arr[i]);
    }
    quicksort(arr,0,n-1);
    printf("\nAfter Sorting: ");
    for(i=0;i<n;i++){
        printf("%d  ",arr[i]);
    }
}

void quicksort(int arr[],int p, int q){
    int m;
    if(p<q){
        m=partition(arr,p,q);
        quicksort(arr,p,m-1);
        quicksort(arr,m+1,q);
    }
}
int partition(int arr[],int p,int q){
    int x,i,j;
    x=arr[p];
    i=p;
    for(j=p+1;j<=q;j++){
        if(arr[j]<=x){
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i],&arr[p]);
    return i;
}

void swap(int *x,int *y){
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}