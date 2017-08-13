#include <stdio.h>

int main()
{
        int n;
        scanf("%d", &n);
        int i;
        long long int fact = 1;
        for (i = 1; i <= n; i++)
                fact = fact * i;
        printf("%lld\n", fact);
        return 0;
}
