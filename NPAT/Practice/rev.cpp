#include <stdio.h>
#include <string.h>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main()
{
        int n;
        scanf("%d", &n);
        //char s[25];
        string s;
        int end, start, i;
                getchar();
        int cs = 1;
        while (n--) {
                getline(cin, s);
                int len = s.length();//strlen(s);
                end = len;
                i = len - 1;
                int j;
                printf("Case #%d: ", cs);
                while ( i >= 0) {
                        if (s[i] == ' ') {
                                for (j = i + 1; j < end; j++)
                                        printf("%c", s[j]);

                                end = i;
                                printf(" ");
                        }
                        i--;
                }
                for (j = i + 1; j < end; j++)
                        printf("%c", s[j]);
                printf("\n");
                cs++;
        }
        return 0;
}
