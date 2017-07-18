#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
        int col, row;
        //char message[200];
        string message;
        while(1) {
                scanf("%d", &col);
                if (col == 0)
                        break;
                cin >> message;
                row = message.length() / col;
                string enc[row];
                bool rev = false;
                int i, j, k = 0;
                for(i= 0;i < message.length();i+=col) {
                        string temp = message.substr(i, col);
                        if (rev) {
                                reverse(temp.begin(), temp.end());
                        }
                        enc[k++] = temp;
                        rev = !rev;
                }
                for (i = 0;i < col;i++) {
                        for (j = 0;j < row;j++) {
                                cout << enc[j][i];
                        }
                }
                cout << endl;
        }
}
