#include <stdio.h>
#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
        int t, i;
        cin >> t;
        while (t--) {
                string s, t;
                cin >> s >> t;
                map <char, int> occ_a;
                map <char, int> occ_b;
                for (i = 0; i < s.length(); i++) {
                        occ_a[s[i]]++;
                }
                for (i = 0; i < t.length(); i++) {
                        occ_b[t[i]]++;
                }

                bool case1 = false, case2 = true;
                /*
                 * Case1: A has a char with occ > 1 and B doesn't have it
                 * Case 2: All chars in A is present in B
                 */
                for (i = 0; i < s.length(); i++) {
                        if (occ_a[ s[i] ] > 1 && occ_b[ s[i] ] == 0) {
                                case1 = true;
                                break;
                        }
                        if (occ_b[ s[i] ] == 0) {
                                case2 = false;
                        }
                }

                if (case1) {
                        cout << "A" << endl;
                        continue;
                }

                if (case2) {
                        cout << "B" << endl;
                        continue;
                }

                /*
                 * A has given a char
                 * - B doesn't have it
                 * - A doesn't have it
                 */

                /*
                 * If B has a char that A doesn't
                 * He will either win or draw (win)
                 */
                bool notPresent = false;
                for (i = 0; i < t.length(); i++) {
                        if ( occ_a[t[i]] == 0) {
                                notPresent = true;
                                break;
                        }
                }

                if (notPresent) {
                        cout << "B" << endl;
                        continue;
                }
                cout << "A" << endl;
        }
        return 0;
}
