#include <stdio.h>
#include <map>

using namespace std;

bool isLower(char ch)
{
        if (ch >= 'a' && ch <= 'z')
                return true;
        return false;
}

bool isUpper(char ch)
{
        if (ch >= 'A' && ch <= 'Z')
                return true;
        return false;
}

int calculateLen(char *str, int pos1, int pos2)
{
        int i;
        map<char, int> freq;

        for (i = pos1; i <= pos2; i++) {
                freq[str[i]]++;
        }

        return freq.size();
}

int main()
{
        int n;
        scanf("%d", &n);
        char str[n + 1];
        scanf("%s", str);

        int maxLen = 0, len;
        int i, pos1 = -1, pos2;
        for (i = 0; i < n; i++) {
                if (isUpper(str[i]) || (isLower(str[i]) && (i == n - 1)) ) {
                        if (isUpper(str[i]) && pos1 == -1)
                                continue;
                        pos2 = isUpper(str[i]) ? (i - 1) : i;
                        pos1 = (pos1 == -1) ? i : pos1;
                        len = calculateLen(str, pos1, pos2);
                        if (len > maxLen)
                                maxLen = len;

                        pos1 = -1;
                }
                if (isLower(str[i])) {
                        if (pos1 != -1)
                                continue;
                        pos1 = i;
                }
        }
        printf("%d\n", maxLen);
        return 0;
}
