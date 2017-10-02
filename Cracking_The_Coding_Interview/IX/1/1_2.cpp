#include <iostream>
#include <string>
#include <map>

std::map<char, int> calculateFreq(std::string str)
{
        std::map<char, int> freq;
        int i;
        for (i = 0; i < str.length(); i++)
                freq[ str[i] ]++;

        return freq;
}

bool compareMaps(std::map<char, int> occ1, std::map<char, int> occ2)
{
        return occ1.size() == occ2.size() && std::equal(occ1.begin(), occ1.end(), occ2.begin());
}

int main()
{
        std::string str1, str2;
        std::map<char, int> str1_occ, str2_occ;

        std::cin >> str1 >> str2;

        str1_occ = calculateFreq(str1);
        str2_occ = calculateFreq(str2);

        if (compareMaps(str1_occ, str2_occ))
                std::cout << "They are a permutation" << std::endl;
        else
                std::cout << "They are NOT a permutation" << std::endl;
        return 0;
}
