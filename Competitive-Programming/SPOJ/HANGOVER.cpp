#include <stdio.h>

using namespace std;

int main()
{
        float values[301];
        float sum = 0.0f;
        int i;
        for (i = 1; i <= 300; i++) {
                sum += 1 / ((i + 1) * 1.0f);
                values[i] = sum;
                //printf(" [%d] = %0.2f\n", i, values[i]);
        }
        while (1) {
        float res;
                scanf("%f", &res);
                if (res == 0.0f)
                        break;
                for (i = 1; i <= 300; i++)
                        if (values[i] >= res) {
                                printf("%d card(s)\n", i);
                                break;
                        }
        }
        return 0;
}
