#include <stdio.h>
#include <iostream>

#define ll long long int

using namespace std;

void goto_tank(ll *gasoline, int f)
{
        *gasoline -= f;
}

void return_to_tank(ll *gasoline, int dist)
{
        *gasoline -= dist;
}

void fill_tank(ll *gasoline, int *min_fill_amt, ll b)
{
        *gasoline = b;
        *min_fill_amt = *min_fill_amt + 1;
}

void go_home(ll *gasoline, int f)
{
        *gasoline -= f;
}

int main()
{
        int a, f, k;
        ll b;

        cin >> a >> b >> f >> k;

        int curr_journey = 0;
        ll gasoline = b;
        int min_fill_amt = 0;
        int x;

        while (curr_journey <= k) {
                goto_tank(&gasoline, f);
                cout << "At tank. Journey no:" << curr_journey << ": " << gasoline << endl;

                /*
                if (gasoline < 0 ) {
                        cout << "-1" << endl;
                        return 0;
                }
                */

                if (gasoline >= (2 * (a - f) )) {
                        return_to_tank(&gasoline, (2 * (a - f) ));
                } else {
                        cout << "Gasoline left: " << gasoline << " Fill amt: " << min_fill_amt << endl;
                        fill_tank(&gasoline, &min_fill_amt, b);
                        cout << "Filled. Gasoline left: " << gasoline << endl;
                        return_to_tank(&gasoline, (2 * (a - f)));
                        cout << "Gasoline left: " << gasoline << " Fill amt: " << min_fill_amt << endl;
                        /*
                        if (gasoline < 0) {
                                cout << "-1" << endl;
                                return 0;
                        }
                        */
                }

                if (curr_journey == k - 1) {
                        cout << "Last stop. Gasoline left: " << gasoline << endl;
                        if (gasoline < f) {
                                fill_tank(&gasoline, &min_fill_amt, b);
                                cout << "Filled. Gasoline left: " << gasoline << endl;
                                if (gasoline < f) {
                                        cout << "-1\n";
                                        return 0;
                                }
                        }
                } else {
                        if (gasoline < (2 * f)) {
                                cout << "Gasoline left: " << gasoline << " Fill amt: " << min_fill_amt << endl;
                                fill_tank(&gasoline, &min_fill_amt, b);
                                cout << "Filled. Gasoline left: " << gasoline << endl;
                                if (gasoline < 2 * f) {
                                        cout << "-1\n";
                                        return 0;
                                }
                        }
                }
                go_home(&gasoline, f);
                curr_journey++;
                cout << "HOME. Gasoline left: " << gasoline << endl;
        }
        printf("%d\n", min_fill_amt);
        return 0;
}
