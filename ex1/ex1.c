#include <stdio.h>

// O(n)
int arrMax(int arr[], int size)
{
    int max = arr[0];
    for (size_t i = 1; i < size; i++)
    {
        max = (max > arr[i])? max : arr[i];
    }
    return max;
}

int main()
{
    int arr[] = {2, 4, 1, -4, 6, 9, 8};
    int size = sizeof(arr)/ sizeof(arr[0]);
    int result = arrMax(arr, size);
    printf("%d", result);
}