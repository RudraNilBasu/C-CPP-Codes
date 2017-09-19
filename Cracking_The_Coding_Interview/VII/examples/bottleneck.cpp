#include <stdio.h>
#include <map>
#include <stdlib.h>

int* takeInput(int* n, int* k)
{
        scanf("%d", n);
        int *a = (int *) malloc((*n) * sizeof(int));

        int i;
        for (i = 0; i < *n; i++)
                scanf("%d", (a + i));

        scanf("%d", k);
        return a;
}

int main()
{
        int n, k;
        int *a = takeInput(&n, &k);
        
        std::map<int, bool> occurance;
        int i;

        for (i = 0; i < n; i++) {
                occurance[ a[i] ] = true;
        }

        int count = 0;
        for (i = 0; i < n; i++) {
                int numToFind = a[i] + k;
                if (occurance[numToFind]) {
                        count++;
                        printf("%d. (%d, %d)\n", count, a[i], (a[i] + k));
                }
        }
}
