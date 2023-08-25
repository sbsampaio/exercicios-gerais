#include <stdio.h>

int main()
{
    int n;

    scanf("%d", &n);

    int lines = n;
    int size;
    int count = 1;
    
    while (lines--)
    {
        size = n - lines;
        while (size--)
        {
            printf("%d ", count);
            count++;
        }
        printf("\n");
    }

    return 0;
}
