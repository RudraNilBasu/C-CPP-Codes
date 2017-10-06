#include <iostream>
#include <string>
#include <sstream>

void compress(std::string s1)
{
        int i = 0, j;
        std::string compressed = "";
        while (i < s1.length()) {
                compressed += s1[i];

                j = i + 1;
                int count = 1;
                while (s1[j] == s1[i] && j < s1.length()) {
                        j++;
                        count++;
                }
                std::cout << s1[i] << count;
                //compressed += std::to_string(count);;
                i = j;
        }
        std::cout << "\n";
        //return compressed;
}

int main()
{
        std::string s1;
        std::cin >> s1;

        compress(s1);
        //std::cout << compress(s1) << std::endl;
        return 0;
}
