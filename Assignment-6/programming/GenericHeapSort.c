#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int (*Compare)(const void *, const void *);
void swap(void *a, void *b, size_t size)
{
    void *temp = malloc(size);

    memcpy(temp, a, size);
    memcpy(a, b, size);
    memcpy(b, temp, size);

    free(temp);
}
void heapify(void *arr, int n, int i, size_t size, Compare cmp)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    char *base = (char *)arr;

    void *current = base + i * size;
    void *leftElement = base + left * size;
    void *rightElement = base + right * size;

    if (left < n && cmp(leftElement, current) > 0)
    {
        largest = left;
    }

    current = base + largest * size;

    if (right < n && cmp(rightElement, current) > 0)
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(base + i * size, base + largest * size, size);
        heapify(arr, n, largest, size, cmp);
    }
}

void heapSort(void *arr, int n, size_t size, Compare cmp)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i, size, cmp);
    }
    for (int i = n - 1; i > 0; i--)
    {

        swap((char *)arr, (char *)arr + i * size, size);
        heapify(arr, i, 0, size, cmp);
    }
}
int compareInt(const void *a, const void *b)
{

    int x = *(const int *)a;
    int y = *(const int *)b;

    if (x > y)
        return 1;

    if (x < y)
        return -1;

    return 0;
}
int compareFloat(const void *a, const void *b)
{

    float x = *(const float *)a;
    float y = *(const float *)b;

    if (x > y)
        return 1;

    if (x < y)
        return -1;

    return 0;
}
int main()
{

    int arr[] = {10, 3, 7, 1, 8, 5, 2};

    int n = sizeof(arr) / sizeof(arr[0]);
    float arr2[] = {3.5, 1.2, 8.7, 2.4};
    int n2= sizeof(arr2) / sizeof(arr2[0]);
    heapSort(arr2,n2,sizeof(float),compareFloat);
     for (int i = 0; i < n2; i++)
    {
        printf("%f ", arr2[i]);
    }
    heapSort(arr,n,sizeof(int),compareInt);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}