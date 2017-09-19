#include <stdio.h>
#include <map>

using namespace std;

int abs(int x)
{
        return (x < 0) ? (-1 * x) : x;
}

int main()
{
        int i, x, n;
        scanf("%d %d", &n, &x);
        int a[n];
        int count = 0;
        map<int, bool> occurance;
        for (i = 0; i < n; i++) {
                scanf("%d", (a+i));
                occurance[ a[i] ] = true;
        }

        if (occurance[x])
                count++;

        for (i = 0; i < x; i++) {
                if (!occurance[i]) {
                        count++;
                }
        }

        printf("%d\n", count);
        return 0;
}
