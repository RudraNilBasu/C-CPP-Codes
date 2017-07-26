#include <stdio.h>
#include <string.h>

#define MAX 9223372036854775807
#define ull unsigned long long int

char num[5001];
int n;

ull test[5001];

ull calc(int pos)
{
        if (pos > n) {
                return 0;
        }
        if (pos == n) {
                return 1;
        }
        if (pos <= n - 2) {
                if (num[pos] <= '2' && num[pos + 1] <= '6') {
                        return (calc(pos + 1)) + (calc(pos + 2));
                }
        }
        if (num[pos] == '0')
                return 0;
        return calc(pos + 1);
}

int get_num(char a, char b)
{
        return ((a - '0') * 10 ) + (b - '0');
}

ull bottom_up()
{
        test[n - 1] = (num[n - 1] == '0') ? 0 : 1;
        int i;
        if (get_num(num[n - 2], num[n - 1]) <= 26 && get_num(num[n - 2], num[n - 1]) > 9) {
                test[n - 2] = (num[n - 1] == '0') ? 1 :2;
        } else {
                test[n - 2] = (num[n - 1] == '0' || num[n - 2] == '0') ? 0 : 1;
        }
        for (i = n - 3; i >= 0; i--) {
                //if (num[i] <= '2' && num[i + 1] <= '6') {
                if (get_num(num[i], num[i + 1]) <= 26 && get_num(num[i], num[i + 1]) > 9) {
                        test[i] = (test[i + 1] % MAX + test[i + 2] % MAX) % MAX;
                } else if (num[i] == '0'){
                        test[i] = 0;//test[i + 1];
                } else {
                        test[i] = test[i + 1];
                }
        }
        printf("%llu\n",test[0]);
}

int main()
{
        int i;
        while (1) {
                scanf("%s",num);
                n = strlen(num);
                if (n == 1 && num[0] == '0') {
                        break;
                }
                bottom_up();
        }
        return 0;
}
