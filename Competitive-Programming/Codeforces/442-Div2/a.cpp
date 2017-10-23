#include <iostream>
#include <string>

using namespace std;

int find_occurance(string str, string sub)
{
        int count = 0;
        size_t nPos = str.find(sub, 0);
        while (nPos != string::npos) {
                count++;
                nPos = str.find(sub, nPos + 1);
        }
        return count;
}

int main()
{
        string names[5] = {"Danil", "Olya", "Slava", "Ann", "Nikita"};
        string s;
        cin >> s;
        int i;
        int count = 0;
        for (i = 0; i < 5; i++) {
                count += find_occurance(s, names[i]);
        }

        if (count == 1)
                cout << "YES\n";
        else
                cout << "NO\n";
        return 0;
}
