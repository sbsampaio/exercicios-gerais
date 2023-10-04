#include <stdio.h>
#include <math.h>

int main()
{
    int decimal;

    scanf("%d", &decimal);

    int result = decimal;
    int rest;
    int i = 0;

    while (result != 0)
    {
        rest += (result % 8) * (int)pow(10, i);
        result = result / 8;
        i++;
    }

    printf("%d\n", rest);

    return 0;
}