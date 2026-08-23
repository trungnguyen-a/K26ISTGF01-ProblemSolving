#include <stdio.h>
#include <malloc.h>

void arrIntersect(int arr1[], int arr2[], int size1, int size2)
{
    int* tempArr = malloc(4 * sizeof(int));
    
    // O(n^2) or O(n*m)
    int tempArrIndex = 0;
    for (size_t i = 0; i < size1; i++)
    {
        for (size_t k = 0; k < size2; k++)
        {
            if (arr1[i] == arr2[k])
            {
                tempArr[tempArrIndex] = arr1[i];
                tempArrIndex++;
            }
        }
    }

    // O(n)
    for (size_t i = 0; i < tempArrIndex; i++)
    {
        printf("%d ", tempArr[i]);
    }
    
    free(tempArr);
}


int main() 
{
    int arr1[] = {3, 2, 1, 8, 9};
    int arr2[] = {4, 1, 7, 3, 9, 10, 8};
    int sizeArr1 = sizeof(arr1)/sizeof(arr1[0]);
    int sizeArr2 = sizeof(arr2)/sizeof(arr2[0]);

    arrIntersect(arr1, arr2, sizeArr1, sizeArr2);
}