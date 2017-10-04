#include <iostream>
#include <string>
#include <map>

int abs(int x)
{
        return (x > 0) ? x : -1 * x;
}

bool oneWay(std::string s1, std::string s2, int edits)
{
        if ( (abs(s1.length() - s2.length()) > 1) || (edits > 1) )
                return false;

        if (s1.length() == 0 && s2.length() == 0)
                return true;

        if (s1.length() == 0 && s2.length() == 1) {
                if (edits == 1)
                        return false;
                return true;
        }

        if (s2.length() == 0 && s1.length() == 1) {
                if (edits == 1)
                        return false;
                return true;
        }

        if ( s1.length() == 0 || s2.length() == 0 )
                return false;

        if (s1[0] == s2[0])
                return oneWay(s1.substr(1), s2.substr(1), edits);

        if (edits >= 1)
                return false;

        return (
                        oneWay(s1, s2.substr(1), edits + 1) || 
                        oneWay(s1, s1[0] + s2, edits + 1) || 
                        oneWay(s1, s1[0] + s2.substr(1), edits + 1)
                        );
}

bool checkReplacement(std::string, std::string);
bool checkInsert(std::string, std::string);

bool oneWay2(std::string s1, std::string s2)
{
        if (s1.length() == s2.length())
                return checkReplacement(s1, s2);
        if ((s1.length() - s2.length()) == 1)
                return checkInsert(s2, s1);
        if ((s1.length() - s2.length()) == -1)
                return checkInsert(s1, s2);

        return false;
}

bool checkReplacement(std::string s1, std::string s2)
{
        int i, replacement = 0;
        for (i = 0; i < s1.length(); i++) {
                if (s1[i] != s2[i]) {
                        replacement++;
                        if (replacement > 1)
                                return false;
                }
        }
        return (replacement <= 1);
}

bool checkInsert(std::string s1, std::string s2)
{
        int i, k = 0, edits = 0;
        for (i = 0; i < s1.length(); i++, k++) {
                if (s1[i] != s2[k]) {
                        k++;
                        edits++;
                        if (edits > 1)
                                return false;
                }
        }
        return true;
}

int main()
{
        std::string s1, s2;

        std::cin >> s1 >> s2;
        std::cout << (oneWay(s1, s2, 0) == true ? "true" : "false") << std::endl;
        std::cout << (oneWay2(s1, s2) == true ? "true" : "false") << std::endl;
}
