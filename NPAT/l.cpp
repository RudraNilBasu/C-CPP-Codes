#include <iostream>

using namespace std;

int has(int *a, int n, int x, int k) {
        // Write your code is this space


        if (n == 1) {
                if (k == 0)
                        return 1;
                if ((k == 1) && (a[0] == x))
                        return 1;
                return 0;
        }

        if(a[n-1] == x) {
                return has(a, n-1, x, k-1);
        } else {
                return has(a, n-1, x, k);
        }
}
