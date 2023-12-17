#include <stdio.h>
void main(void) {
  int arr[50],i,n,key,flag;
  printf("Enter the array Size: ");
  scanf("%d",&n);
  printf("\nEnter %d numbers: ",n);
  for(i=0;i<n;i++)
  scanf("%d",&arr[i]);
printf("\nYour Entered numbers are: ");
  for(i=0;i<n;i++)
  printf("%d ",arr[i]);
  printf("\nEnter the search element: ");
  scanf("%d",&key);
for(i=0;i<n;i++){
  if(arr[i]==key){
printf("\n%d is Found at %d Position",key,i+1);
flag=1;
return;
}
  else
flag=0;
}
if(flag==0)
printf("\n%d is not Present/Found in this Array",key);
return;
}
