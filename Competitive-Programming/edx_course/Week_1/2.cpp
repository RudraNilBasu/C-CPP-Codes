#include <iostream>

#define ll long long int

int main()
{
#ifdef JUDGE
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
#endif

        ll a, b;
        std::cin >> a >> b;
        std::cout << (a + (b * b)) << std::endl;
}
