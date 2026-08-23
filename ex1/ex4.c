#include <stdio.h>

// O(n)
void arrayInsertAt(int arr[], int* arr_size,int item, int index)
{
    int times = *arr_size - index;
    while (times > 0)
    {
        arr[times + 1] = arr[times];
        times--;
    }
    arr[index] = item;
    *arr_size = *arr_size+1;
}


int main()
{
    int arr[10] = {2, 4, 5, 7, 8};
    int arrSize = 5;
    
    arrayInsertAt(arr, &arrSize, 3, 1);
    for (size_t i = 0; i < arrSize; i++)
    {
        printf("%d ", arr[i]);
    }
}