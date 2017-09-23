#include <stdio.h>
#include <iostream>
#include <map>

#define ll long long int

typedef struct pair {
        int x;
        int y;
}pair;

int main()
{
        std::map<ll, pair> hash;
        int a, b, c, d, n = 1000;

        for (c = 1; c <= n; c++) {
                for (d = 1; d <= n; d++) {
                        ll val = (c*c*c) + (d*d*d);
                        pair temp;
                        temp.x = c;
                        temp.y = d;
                        hash[val] = temp;
                }
        }

        std::map<ll, pair>::iterator it;
        for (a = 1; a <= n; a++) {
                for (b = 1; b <= n; b++) {
                        ll val = (a*a*a) + (b*b*b);
                        it = hash.find(val);
                        if (it != hash.end()) {
                                pair _p = hash[val];
                                std::cout << a << " , " << b << " , " << _p.x << " , " << _p.y << std::endl;
                        }
                }
        }
}
