#include <stdio.h>
#include <iostream>

using namespace std;

int check()
{
        int n, rho;
        cin >> n >> rho;
        if (n & 1) {
                //
        } else {
                int avg = 25;
                for (int i = 1; i <= (n / 2); i++) {
                        cout << avg - (i * rho) << endl;
                }
                for (int i = 1; i <= (n / 2); i++) {
                        cout << avg + (i * rho) << endl;
                }
        }
}

int main()
{
        int t;
        cin >> t;
        while (t--) {
                check();
        }
        return 0;
}
