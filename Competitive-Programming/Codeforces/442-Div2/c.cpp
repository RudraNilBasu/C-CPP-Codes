#include <iostream>
#include <vector>

using namespace std;

int main()
{
        int n;
        cin >> n;

        vector<int> pos;

        int mid = (n / 2) + (n & 1) ? 1 : 1;

        int count = 0, i;
        for (i = mid; i >= 1; i-= 2) {
                count++;
                pos.push_back(i);
        }

        int st = (n & 1) ? 1 : 2;
        for (i = 1; st < mid; i += 2) {
                count++;
                pos.push_back(i);
        }

        for (i = mid + 2; i <= n; i+= 2) {
                count++;
                pos.push_back(i);
        }

        //st = (n & 2) ? n : ;

        for (i = n; i >= mid; i -= 2) {
                count++;
                pos.push_back(i);
        }
        cout << count << endl;
        for (i = pos.size() - 1; i >= 0; i--) {
                cout << pos[i] << " ";
        }
        cout << endl;
}
