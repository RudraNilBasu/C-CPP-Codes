#include <stdio.h>

using namespace std;

int main()
{
        int n, i;
        while (1) {
                scanf("%d", &n);
                if (n == 0)
                        break;
                int a[n + 1];
                //int pos[n + 1];
                bool amb = true;
                for (i = 1; i <= n; i++) {
                        scanf("%d", (a + i));
                }
                for (i = 1; i <= n; i++) {
                        //pos[ a[i] ] = (i + 1);
                        if (a[ a[i] ] != (i)) {
                                amb = false;
                                //break;
                        }
                }
                if (amb)
                        printf("ambiguous\n");
                else
                        printf("not ambiguous\n");
                /*
                for (i = 1; i <= n; i++)
                        printf("%d\n",pos[i]);
                 */
        }
        return 0;
}
