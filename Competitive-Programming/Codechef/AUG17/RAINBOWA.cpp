#include <stdio.h>

using namespace std;

int main()
{
        int t, n;
        scanf("%d", &t);
        while (t--) {
                scanf("%d", &n);
                int arr[n];
                int a[11];
                int curr_no = 1;
                int k = 0, i = 0;
                for (i = 1; i <= 10; i++)
                        a[i] = 0;
                for (i = 0; i < n; i++) {
                        scanf("%d", arr+i);
                        a[arr[i]]++;
                }
                int flag = 0;
                for (i = 1; i <= 7; i++) {
                        if (a[i] == 0) {
                                flag = 1;
                                break;
                        }
                }
                if (flag) {
                        printf("no\n");
                        continue;
                }
                for (i = 0; i < n - 1; i++) {
                        if (arr[i] == 7 && arr[i + 1] != 7) {
                                //k = i;
                                break;
                        }
                        if (arr[i] > arr[i + 1]) {
                                flag = 1;
                                break;
                        }
                }
                if (flag) {
                        printf("no\n");
                        continue;
                }
                for (i = 0; i < n; i++) {
                        if (arr[i] != arr[n - i - 1]) {
                                flag = 1;
                                break;
                        }
                }
                if (flag) {
                        printf("no\n");
                } else {
                        printf("yes\n");
                }
        }
        return 0;
}
