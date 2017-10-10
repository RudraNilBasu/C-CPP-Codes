#include <iostream>

using namespace std;

#define ll long long int

int lastDigit(ll digit)
{
        return digit % 10;
}

int main()
{
        ll a, b, i;
        cin >> a >> b;
        if (a == b) {
                cout << "1\n";
                return 0;
        }
        int x = lastDigit(a + 1);
        for (i = a + 2; i <= b; i++) {
                x = lastDigit((lastDigit(i) * lastDigit(x)));
                if (x == 0)
                        break;
        }
        cout << lastDigit(x) << endl;
}
