#include<stdio.h>
void mergesort(int[],int, int);
void merge(int[],int,int,int);
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
    mergesort(arr,0,n-1);
    printf("\nAfter Sorting: ");
    for(i=0;i<n;i++){
        printf("%d  ",arr[i]);
    }
}

void mergesort(int arr[],int p, int r){
    int q;
    if(p<r){
        q=(p+r)/2;
    mergesort(arr,p,q);
    mergesort(arr,q+1,r);
    merge(arr,p,q,r);
    }
}

void merge(int arr[],int p,int q,int r){
    if (p > r) 
        return;
    int n1,n2,i,j,k;
    n1=q-p+1;
    n2=r-q;
    int L[n1+1],R[n2+1];
    for (i=0;i<n1;i++){
        L[i]=arr[p+i];
    }
    for (i=0;i<n2;i++){
        R[i]=arr[q+1+i];
    }
    L[n1]=999999999;
    R[n2]=999999999;
    i=0;
    j=0;
    for(k=p;k<=r;k++){
        if(L[i]<=R[j]){
            arr[k]=L[i];
            i=i+1;
        }
        else{
            arr[k]=R[j];
            j=j+1;
        }
    }
}