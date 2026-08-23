#include <stdio.h>
#include <malloc.h>


// O(n^2)
void reverseArray(int arr[], int size)
{
    int* reverseArr = malloc(size * sizeof(int));

    for (int i = size - 1, k = 0; i >= 0; i--, k++)
    {
        reverseArr[k] = arr[i];
    }
    
    for (size_t i = 0; i < size; i++)
    {
        printf("%d ",reverseArr[i]);
    }
    
    free(reverseArr);
}


int main()
{
    int arr[] = {1, 2, 3, 4};
    int size = sizeof(arr)/sizeof(arr[0]);

    reverseArray(arr, size);
}