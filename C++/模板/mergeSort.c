int max(int x, int y)
{
    if (x > y)
    {
        return x;
    }
    return y;
}

int* merge(int* arr, int left1, int right1, int* arr2, int left2, int right2)
{
    int result_size = max(right1 - left1, right2 - left2) * 2;
    int* result = (int*) malloc(sizeof(int) * result_size);
    int ptr = 0;
    int ptrL = left1;
    int ptrR = left2; 
    while (ptrL < right1 && ptrR < right2)
    {
        while (ptrL < right1 && arr[ptrL] < arr2[ptrR])
        {
            result[ptr++] = arr[ptrL++];
        }
        while (ptrR < right2 && arr2[ptrR] <= arr[ptrL])
        {
            result[ptr++] = arr2[ptrR];
            ptrR++;
        }
    }
    while (ptrL < right1)
    {
        result[ptr++] = arr[ptrL++];
    }
    while (ptrR < right2)
    {
        result[ptr++] = arr2[ptrR++];
    }

    return result;
}

void mergeSort(int* arr, int left, int right)
{
    if (left + 1 >= right)
    {
        return;
    }

    int middle = (left + right) / 2;

    mergeSort(arr, left, middle);
    mergeSort(arr, middle, right);

    int* result = (int*) merge(arr, left, middle, arr, middle, right);
    for (int i = left; i < right; i++)
    {
        arr[i] = result[i - left];
    }
}
