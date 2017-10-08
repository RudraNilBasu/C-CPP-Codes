#include <stdio.h>

void swap(int *a, int *b)
{
        int temp = *a;
        *a = *b;
        *b = temp;
}

int hcf(int a, int b)
{
        if (a > b)
                swap(&a, &b);
        if (a == 0)
                return b;

        return hcf(b % a, a);
}

int main()
{
        int a, b;
        scanf("%d %d", &a, &b);
        printf("HCF of %d, %d = %d\n", a, b, hcf(a, b));
        return 0;
}
