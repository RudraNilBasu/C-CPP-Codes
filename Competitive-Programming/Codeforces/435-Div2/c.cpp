#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>

#define ll long long int

using namespace std;

int bitXor(int x, int y)
{
        int a = x & y;
        int b = ~x & ~y;
        return ~a & ~b;
}

int main()
{
        int n, x, i;
        cin >> n >> x;

        if (n == 1) {
                cout << "YES\n" << x << endl;
                return 0;
        }

        if (n == 2) {
                if (x == 0) {
                        cout << "NO" << endl;
                } else {
                        cout << "YES\n" << "0 " << x << endl;
                }
                return 0;
        }
        cout << "YES\n";

        ll sum = 0;
        ll pw = 1 << 17;
        for (i = 1; i <= n - 3; i++) {
                cout << i << " ";
                sum ^= i;
        }

        if (sum == x) {
                cout << pw << " " << (pw * 2) << " " << bitXor(pw, pw * 2) << endl;
        } else {
                cout << "0 " << pw << " " << bitXor(pw, bitXor(x, sum)) <<  endl;
        }
        return 0;
}
