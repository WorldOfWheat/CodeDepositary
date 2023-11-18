#include <stdio.h>
#include <stdlib.h>

int main() 
{
    while (1)
    {
        int n;
        scanf("%d", &n);
        if (n == 0)
        {
            break;
        }

        while (1)
        {
            int* arr;
            arr = (int*) malloc(n*sizeof(int));
            scanf("%d", arr);
            if (*arr == 0)
            {
                break;
            }
            for (int i = 1; i < n; i++)
            {
                scanf("%d", (arr + i));
            }

            int* stack;
            stack = (int*) malloc(n*sizeof(int));
            int tail = -1;
            int now = 0;
            for (int i = 1; i <= n; i++)
            {
                tail++;
                *(stack + tail) = i;
                while (tail >= 0 && *(arr + now) == *(stack + tail))
                {
                    tail--;
                    now++;
                }
            }

            if (tail == -1)
            {
                printf("Yes\n");
            }
            else
            {
                printf("No\n");
            }
        }
    }

    return 0;
}