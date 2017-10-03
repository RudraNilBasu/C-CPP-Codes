#include <iostream>
#include <string>
#include <map>

char toLowerCase(char ch)
{
        if (ch >= 'a' && ch <= 'z')
                return ch;

        if (ch >= 'A' && ch <= 'Z')
                return ch + 32;

        return ch;
}

bool checkPalindromePermutation(std::string str)
{
        std::map<char, int> freq;
        int i;

        for (i = 0; i < str.length(); i++)
                freq[ toLowerCase(str[i]) ]++;

        int alphabets = str.length() - freq[' '];

        char ch;
        int odd_alphabets = 0;
        for (ch = 'a'; ch <= 'z'; ch++) {
                if (freq[ch] & 1) {
                        odd_alphabets++;
                        if (odd_alphabets > 1)
                                return false;
                }
        }

        return true;
}

bool checkPalindromePermutation2(std::string str)
{
        int i, bit = 0;
        int spaces = 0, alphabets;
        for (i = 0; i < str.length(); i++) {
                if (str[i] == ' ')
                        spaces++;
                char ch = toLowerCase(str[i]);
                if (ch < 'a' || ch > 'z')
                        continue;
                bit = bit ^ (1 << ((ch - 'a') + 1));
        }
        alphabets = str.length() - spaces;
        if (alphabets % 2 == 0) {
                return (bit == 0);
        } else {
                return (bit & (bit - 1)) == 0 ? true : false;
        }
}

int main()
{
        std::string str = "Tact Coa";

        std::cout << str << " is" << (checkPalindromePermutation2(str) ? " ": " NOT ") << "a Palindrome permutation\n";
        std::cout << "tactcoapapa" << " is" << (checkPalindromePermutation2("tactcoapapa") ? " ": " NOT ") << "a Palindrome permutation\n";
        std::cout << "aba b" << " is" << (checkPalindromePermutation2("tactcoapapa") ? " ": " NOT ") << "a Palindrome permutation\n";
        return 0;
}
