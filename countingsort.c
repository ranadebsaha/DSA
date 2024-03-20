#include <stdio.h>
void countingsort(int[], int[], int, int);
int max(int[], int);
void main()
{
    int A[100], B[100], i, n, k;
    printf("Enter size of the array: ");
    scanf("%d", &n);
    printf("Enter number one by one: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }
    k = max(A, n);
    printf("Before sorting the Array is: ");
    for (i = 0; i < n; i++)
    {
        printf("%d  ", A[i]);
    }
    printf("\nAfter sorting the Array is: ");
    countingsort(A, B, n, k);
    for (i = 0; i < n; i++)
    {
        printf("%d  ", B[i]);
    }
}

void countingsort(int A[], int B[], int n, int k)
{
    int C[k+1], i;
    for (i = 0; i < k+1; i++)
    {
        C[i] = 0;
    }
    for (i = 0; i < n; i++)
    {
        C[A[i]] = C[A[i]] + 1;
    }
    for (i = 1; i < k+1; i++)
    {
        C[i] = C[i] + C[i - 1];
    }
    for (i = n-1; i >=0; i--)
    {
        B[C[A[i]]-1] = A[i];
        C[A[i]] = C[A[i]] - 1;
    }
}

int max(int A[], int n)
{
    int i, k = A[0];
    for (i = 1; i < n; i++)
    {
        if (A[i] > k)
        {
            k = A[i];
        }
    }
    return k;
}