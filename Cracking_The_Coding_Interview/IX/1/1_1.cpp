#include <stdio.h>
#include <string>
#include <algorithm>
#include <iostream>

bool hasDuplicates(std::string str)
{
        // w/o additional data structure
        std::sort(str.begin(), str.end());
        int i;
        for (i = 0; i < str.length() - 1; i++) {
                if (str[i] == str[i + 1])
                        return true;
        }
        return false;
}

bool hasDuplicates2(std::string str)
{
        // with additional ds, considering all lowercase
        int checker = 0;
        int i;
        for (i = 0; i < str.length(); i++) {
                int val = str[i] - 'a';
                if (checker & (1 << val))
                        return true;
                checker |= (1 << val);
        }
        return false;
}

int main()
{
        std::string str;
        std::cin >> str;
        if(hasDuplicates(str)) {
                std::cout << "Duplicates Present\n";
        } else {
                std::cout << "No Duplicates Present\n";
        }

        return 0;
}
