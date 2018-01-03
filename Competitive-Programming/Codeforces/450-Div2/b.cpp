#include <iostream>
#include <map>

using namespace std;

#define ll long long int

int main()
{
        int a, b, c;
        cin >> a >> b >> c;

        map<int, int> pos, rem_occ;

        int rem = a % b;
        int num_pos = 0;

        while ((rem != 0) && (rem_occ.find(rem) == rem_occ.end()) ) {
                num_pos++;
                rem_occ[rem] = 1;
                rem *= 10;

                int num = rem / b;
                /*
                if (pos[num] <= 0)
                        pos[num] = num_pos;
                        */
                if (num == c) {
                        cout << num_pos << endl;
                        return 0;
                }

                rem = rem % b;
        }
        num_pos++;

        if (rem == 0 && c == 0)
                cout << num_pos << endl;
        else
                cout << "-1\n";
        return 0;
}
