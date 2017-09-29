#include <iostream>
#include <string>
#include <cmath>

int getNum(char);

int convert(std::string number, int base)
{
        if (base < 2 || (base > 10 && base != 16)) return -1;

        int len = number.length();
        int i, value = 0;

        for (i = len - 1; i >= 0; i-- ) {
                int n = getNum(number[i]);
                if (n >= base) return -1;

                int exp = len - 1 - i;
                value += n * pow(base, exp);
        }
        return value;
}

bool compareBinToHex(std::string binary, std::string hex)
{
        int n1 = convert(binary, 2);
        int n2 = convert(hex, 16);

        if (n1 < 0 || n2 < 0)
                return false;

        return n1 == n2;
}

int getNum(char ch)
{
        return 1;
}

int main()
{
        return 0;
}
