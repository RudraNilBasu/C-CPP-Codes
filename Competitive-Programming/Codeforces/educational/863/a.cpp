#include <iostream>

#define ll long long int

using namespace std;

void stripZ(ll* n)
{
        while (*n != 0) {
                if ( ((*n) % 10) != 0)
                        return;
                *n = *n / 10;
        }
        return;
}

bool isPalin(ll n)
{
        ll m = n;
        ll rev = 0;
        while (m != 0) {
                rev = (rev * 10) + (m % 10);
                m /= 10;
        }

        return rev == n;
}

int main()
{
        ll n;
        cin >> n;
        stripZ(&n);
        if (isPalin(n))
                cout << "YES\n";
        else
                cout << "NO\n";
        return 0;
}
