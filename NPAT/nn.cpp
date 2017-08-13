#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
        long long int n;
        string s;
        vector<string> ss;
        while (getline(cin, s) && !cin.eof()) {
                if (s.empty())
                        break;
                ss.push_back(s);
                //cout << s << endl;
        }
        int i;
        for (i = ss.size() / 2; i < ss.size(); i++) {
                cout << ss[i] << endl;
        }
        for (i = 0; i < ss.size() / 2; i++) {
                cout << ss[i] << endl;
        }
        return 0;
}
