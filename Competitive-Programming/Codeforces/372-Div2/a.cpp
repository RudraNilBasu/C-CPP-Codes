#include <iostream>
#define ll long long int

using namespace std;

int main()
{
        int n, c;
        cin >> n >> c;

        int a[n];
        int i;
        for (i = 0; i < n; i++) {
                cin >> a[i];
        }

        int words_currently_on_screen = 1;
        for (i = 1; i < n; i++) {
                if ((a[i] - a[i - 1]) > c) {
                        words_currently_on_screen = 1;
                } else {
                        words_currently_on_screen++;
                }
        }

        cout << words_currently_on_screen << endl;
        return 0;
}
