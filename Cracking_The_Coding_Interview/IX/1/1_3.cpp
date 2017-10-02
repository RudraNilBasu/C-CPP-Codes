#include <iostream>
#include <string>

std::string convert(std::string str, int len)
{
        int i;
        int shifting_factor = 0;

        int shifting[len];

        for (i = 0; i < len; i++) {
                shifting[i] = shifting_factor;

                if (str[i] == ' ')
                        shifting_factor += 2;
        }

        for (i = len - 1; i >= 0; i--) {
                str[i + shifting[i]] = str[i];
                if (str[i] == ' ') {
                        str[i + shifting[i]] = '%';
                        str[i + shifting[i] + 1] = '2';
                        str[i + shifting[i] + 2] = '0';
                }
        }
        return str;
}

int main()
{
        std::string str;
        int len;

        str = "Mr John Smith    ";
        len = 13;

        str = convert(str, len);
        std::cout << str << std::endl;
}
