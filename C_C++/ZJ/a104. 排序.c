#include <stdio.h>
#include <stdlib.h>

int max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    return b;
}

int* merge(int* arr1, int* arr2, int left1, int right1, int left2, int right2)
{
    int* result;
    int size = max(right1 - left1, right2 - left2);
    result = (int*) malloc(sizeof(int) * size * 2);
    int ptrL = left1;
    int ptrR = left2;
    int ptrResult = 0;
    while (1)
    {
        if (ptrL >= right1 || ptrR >= right2)
        {
            break;
        }

        if (arr1[ptrL] > arr2[ptrR])
        {
            *(result + ptrResult) = arr2[ptrR];
            ptrR++;
        }
        else
        {
            *(result + ptrResult) = arr1[ptrL];
            ptrL++;
        }
        ptrResult++;           
    }
    while (ptrL < right1)
    {
        *(result + ptrResult) = arr1[ptrL];
        ptrL++;
        ptrResult++;
    }
    while (ptrR < right2)
    {
        *(result + ptrResult) = arr2[ptrR];
        ptrR++;
        ptrResult++;
    }

    return result;
}

int* mergeSort(int* arr, int left, int right)
{
    if (left + 1 >= right)
    {
        return arr + left;
    }

    int mid = (right + left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid, right);
    int* result = merge(arr, arr, left, mid, mid, right);
    for (int i = left; i < right; i++)
    {
        // printf("%i ", i);
        arr[i] = *(result + i - left);
    }
    // printf("\n");
}

int main()
{
    int n;
    while (scanf("%i", &n) != EOF)
    {
        int* arr;
        arr = (int*) malloc(sizeof(int) * n);
        for (int i = 0; i < n; i++)
        {
            scanf("%i", arr + i);
        }
        mergeSort(arr, 0, n);
        for (int i = 0; i < n; i++)
        {
            printf("%i ", *(arr + i));
        }
        printf("\n");
    }
}

-----------------------------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

void quickSort(int* arr, int left, int right)
{
    if (left + 1 >= right)
    {
        return;
    }

    int* less = (int*) malloc(sizeof(int) * (right - left));
    int* greater = (int*) malloc(sizeof(int) * (right - left));
    int ptrLess = 0;
    int ptrGreater = 0;
    for (int i = left; i < right - 1; i++)
    {
        if (arr[i] < arr[right - 1])
        {
            *(less + ptrLess) = arr[i];
            ptrLess++;
        }
        else
        {
            *(greater + ptrGreater) = arr[i];
            ptrGreater++;
        }
    }

    quickSort(less, 0, ptrLess);
    quickSort(greater, 0, ptrGreater);

    for (int i = 0; i < ptrLess; i++)
    {
        *(arr + i) = *(less + i);
    }
    *(arr + ptrLess) = arr[right - 1];
    for (int i = 0; i < ptrGreater; i++)
    {
        *(arr + i + ptrLess + 1) = *(greater + i);
    }
}

int main()
{
    int n;
    while (scanf("%i", &n) != EOF)
    {
        int* arr;
        arr = (int*) malloc(sizeof(int) * n);
        for (int i = 0; i < n; i++)
        {
            scanf("%i", arr + i);
        }

        quickSort(arr, 0, n);

        for (int i = 0; i < n; i++)
        {
            printf("%i ", *(arr + i));
        }
        printf("\n");
    }
}
