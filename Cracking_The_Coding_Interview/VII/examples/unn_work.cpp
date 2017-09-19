#include <stdio.h>
#include <math.h>

void brute_force()
{
        for (int a = 1; a <= 1000; a++) {
                for (int b = 1; b <= 1000; b++) {
                        for (int c = 1; c <= 1000; c++) {
                                for (int d = 1; d <= 1000; d++) {
                                        if (((a*a*a) + (b*b*b)) == ((c*c*c) + (d*d*d))) {
                                                printf("%d %d %d %d\n", a, b, c, d);
                                        }
                                }
                        }
                }
        }
}

void process_1()
{
        for (int b = 1; b <= 1000; b++) {
                for (int c = 1; c <= 1000; c++) {
                        for (int d = 1; d <= 1000; d++) {
                                float val = (float)( ( (c*c*c) + (d*d*d) ) - (b*b*b));
                                float a = pow(val, 1/(3.0f));
                                if ( (a - (int) a) == 0.0f ) {
                                        printf("%d %d %d %d\n", (int)a, b, c, d);
                                }
                        }
                }
        }
}

int main()
{
        brute_force();
        process_1();
}
