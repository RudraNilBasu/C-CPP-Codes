#include <string>

bool isSubstring(std::string s1, std::string s2);

bool rotation(std::string s1, std::string s2)
{
        std::string s1s1 = s1 + s1;
        if (isSubstring(s1s1, s2))
                return true;
        return false;
}
