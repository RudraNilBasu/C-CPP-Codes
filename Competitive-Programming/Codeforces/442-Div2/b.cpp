#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <limits.h>

using namespace std;

char str_ch[5000];
int str_count[5000];

int k;

map<char, int> occ;

typedef struct node {
        char ch;
        int occ;
}node;

vector<node> char_occ;

void build_count(string s)
{
        char ch = 'z';
        int i;

        k = 0;
        for (i = 0; i < s.length(); i++) {
                occ[s[i]]++;
                if (s[i] != ch) {
                        ch = s[i];
                        int count = 0, j;
                        for (j = i; j < s.length(); j++) {
                                if (s[j] == s[i]) {
                                        count++;
                                } else {
                                        break;
                                }
                        }
                        /*
                        str_ch[k] = ch;
                        str_count[k] = count;
                        k++;
                        */
                        node n;
                        n.ch = ch;
                        n.occ = count;
                        char_occ.push_back(n);
                }
        }
}

bool isBeautiful()
{
        if (char_occ.size() == 1)
                return true;
        if (char_occ.size() > 3)
                return false;
        if (char_occ.size() == 2)
                return true;
        if (char_occ.size() == 3) {
                if (char_occ[0].ch == 'a' && char_occ[1].ch == 'b' && char_occ[2].ch == 'a')
                        return true;
        }
        return false;
}

int find_min(int st, int end)
{
        int i;
        int min = INT_MAX, index = -1;
        //for (i = 0; i < char_occ.size(); i++) {
        for (i = st; i <= end; i++) {
                if (char_occ[i].occ < min) {
                        min = char_occ[i].occ;
                        index = i;
                }
        }
        return index;
}

void squash()
{
        int i;
        for (i = 0; i < char_occ.size() - 1; i++) {
                if (char_occ[i].ch == char_occ[i + 1].ch) {
                        char_occ[i].occ += char_occ[i + 1].occ;
                        char_occ.erase(char_occ.begin() + (i + 1));
                        i--;
                }
        }
}

int first_b()
{
        int i;
        for (i = 0; i < char_occ.size(); i++) {
                if (char_occ[i].ch == 'b')
                        return i;
        }
}

int last_b()
{
        int i, index;
        for (i = 0; i < char_occ.size(); i++) {
                if (char_occ[i].ch == 'b')
                        index = i;
        }
        return index;
}

int main()
{
        string s;
        cin >> s;

        build_count(s);

        while (!isBeautiful()) {
                int frst = first_b();
                int lst = last_b();
                int index = find_min(frst, lst);
                char_occ.erase(char_occ.begin() + index);
                squash();
        }

        int count = 0, i;
        for (i = 0; i < char_occ.size(); i++) {
                count += char_occ[i].occ;
        }

        cout << count << endl;
        return 0;
}
