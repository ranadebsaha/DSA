#include <stdio.h>
void max_heapify(int[], int, int);
void build_max_heap(int[], int);
void heapsort(int[], int);
void exchange(int[],int, int);
void main()
{
    int A[100], i, n;
    printf("Enter size of the array: ");
    scanf("%d", &n);
    printf("Enter number one by one: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }
    printf("Before sorting the Array is: ");
    for (i = 0; i < n; i++)
    {
        printf("%d  ", A[i]);
    }
    heapsort(A, n-1);
    printf("\nAfter sorting the Array is: ");
    for (i = 0; i < n; i++)
    {
        printf("%d  ", A[i]);
    }
}

void max_heapify(int A[], int i, int n)
{
    int l, r, largest;
    l = 2 * i;
    r = (2 * i) + 1;
    if (l <= n && A[l] > A[i])
    {
        largest = l;
    }
    else
    {
        largest = i;
    }
    if (r <= n && A[r] > A[largest])
    {
        largest = r;
    }
    if (largest != i)
    {
        exchange(A,i, largest);
        max_heapify(A, largest, n);
    }
}

void build_max_heap(int A[], int n)
{
    int i;
    for (i = n / 2; i >= 0; i--)
    {
        max_heapify(A, i, n);
    }
}

void heapsort(int A[], int n)
{
    build_max_heap(A, n);
    int i, heap_size = n;
    for (i = n-1 ; i > 0; i--)
    {
        exchange(A,i,1);
        heap_size--;
        max_heapify(A, 1, n);
    }
}

void exchange(int A[],int a, int b)
{
    int temp;
    temp = A[a];
    A[a] =A[b];
    A[b] = temp;
}