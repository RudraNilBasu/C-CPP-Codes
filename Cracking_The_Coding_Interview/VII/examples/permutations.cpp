#include <iostream>
#include <string>

void getPermutations(std::string prefix, std::string str)
{
        if (str.size() == 0) {
                std::cout << prefix << std::endl;
                return;
        }
        int i;
        for (i = 0; i < str.size(); i++) {
                std::string _str = str.substr(0, i) + str.substr(i + 1);
                getPermutations(prefix + str[i], _str);
        }
}

int main()
{
        std::string str;
        std::cin >> str;

        getPermutations("", str);
        return 0;
}
