#include <string>
#include <iostream>
#include <map>
using namespace std;

string calc(string s, int start, map<char, int> occ)
{
        for (int i = start; i <= (start + 26); i++) {
                if (s[i] == '?') {
                        for (char ch = 'A'; ch <= 'Z'; ch++) {
                                if (occ[ch] == 0) {
                                        s[i] = ch;
                                        occ[ch]++;
                                        break;
                                }
                        }
                }
        }
        for (int i = 0; i < s.length(); i++) {
                if (s[i] == '?')
                        s[i] = 'A';
        }
        return s;
}

int main()
{
        string s;
        cin >> s;

        int i;

        for (i = 0; i < s.length(); i++) {
                int next_len = i + 26;
                if (next_len > s.length() ) {
                        break;
                }
                string sub = s.substr(i, 26);
                map<char, int> occ;
                bool foundNice = true;
                int j;
                for (j = 0; j < sub.length(); j++) {
                        occ[ sub[j] ]++;
                        if (sub[j] == '?') {
                                continue;
                        }
                        if (occ[ sub[j] ] > 1) {
                                foundNice = false;
                                break;
                        }
                }
                if (foundNice) {
                        string ans = calc(s, i, occ);
                        cout << ans << endl;
                        return 0;
                }
                /*
                if ((i + j) - 1 != i)
                        i = (i + j) - 1;
                        */
        }
        cout << "-1\n";
        return 0;
}
