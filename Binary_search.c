//Binary Search By Ranadeb Saha
#include <stdio.h>
void main(void) {
  int arr[50],i,n,key,flag,low,high,mid;
  printf("Enter the array Size: ");
  scanf("%d",&n);
  printf("\nEnter %d Sorted numbers: ",n);
  for(i=0;i<n;i++)
  scanf("%d",&arr[i]);
printf("\nYour Entered numbers are: ");
  for(i=0;i<n;i++)
  printf("%d ",arr[i]);
  printf("\nEnter the search element: ");
  scanf("%d",&key);
low=0;
high=n-1;
while(low<=high){
  mid=(low+high)/2;
  if(arr[mid]==key){
    printf("\n%d is Found at %d Position",key,mid+1);
return;
  }
  else if(arr[mid]>key)
    high=mid-1;
  else
low=mid+1;
}
printf("\n%d is not Present/Found in this Array",key);
return;
}
