void swap(int* numA, int* numB)
{
    int ptrTemp = *numA;
    *numA = *numB;
    *numB = ptrTemp;
}

void quickSort(int* arr, int left, int right)
{
    int middle = arr[(left + right - 1) / 2];   
    int ptrL = left;
    int ptrR = right - 1;
    while (ptrL <= ptrR)
    {
        while (arr[ptrL] < middle)
        {
            ptrL++;
        }
        while (arr[ptrR] > middle)
        {
            ptrR--;
        }
        if (ptrL <= ptrR)
        {
            swap(&arr[ptrL], &arr[ptrR]);
            ptrL++;
            ptrR--;
        }
    }
    if (left < ptrR)
        quickSort(arr, left, ptrR + 1);
    if (ptrL < right)
        quickSort(arr, ptrL, right);
}
