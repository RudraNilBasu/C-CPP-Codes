#include <stdio.h>
#include <string>
#include <map>
#include <iostream>

std::map<char, int> getHash(std::string str)
{
        std::map<char, int> hash;
        for (int i = 0; i < str.size(); i++)
                hash[ str[i] ]++;
        return hash;
}

bool compare(std::map<char, int> a, std::map<char, int> b)
{
        return (a.size() == b.size()) && (std::equal(a.begin(), a.end(), b.begin()));
}

int main()
{
        std::string small, large;
        std::cout << "Enter smaller string: ";
        std::cin >> small;
        std::cout << "Enter large string: ";
        std::cin >> large;

        std::map<char, int> occ;
        std::map<char, int>::iterator it;
        int i;

        occ = getHash(small);

        for (i = 0; i < large.size(); i++) {
                it = occ.find(large[i]);
                if (it != occ.end() && ((i - 1) + small.size() < large.size())) {
                        std::string sub = large.substr(i, small.size());
                        std::map<char, int> sub_hash = getHash(sub);

                        if( compare(occ, sub_hash) )
                                std::cout << sub << std::endl;
                }
        }
        return 0;
}
