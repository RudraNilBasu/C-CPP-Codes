#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

bool machua(string str)
{
        int i;
        for (i = 0; i < str.length(); i++)
                if (str[i] == 'm')
                        return true;
        return false;
}

int stoi(string str)
{
        int i, num = 0;
        for (i = 0; i < str.length(); i++)
                num = (num * 10) + (str[i] - '0');
        return num;
}

int main()
{
        int t;
        scanf("%d", &t);
        string left, middle, right;
        char sign, equals;
        int l_no, m_no, r_no;
        while (t--) {
                cin >> left >> sign >> middle >> equals >> right;
                //cout << left << sign << middle << equals << right << endl;
                if (machua(left)) {
                        m_no = stoi(middle);
                        r_no = stoi(right);
                        l_no = r_no - m_no;
                } else if (machua(middle)) {
                        l_no = stoi(left);
                        r_no = stoi(right);
                        m_no = r_no - l_no;
                } else if (machua(right)) {
                        l_no = stoi(left);
                        m_no = stoi(middle);
                        r_no = l_no + m_no;
                }
                cout << l_no << " + " << m_no << " = " << r_no << endl;
        }
        return 0;
}
