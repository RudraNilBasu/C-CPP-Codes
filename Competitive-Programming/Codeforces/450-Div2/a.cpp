#include <iostream>

using namespace std;

typedef struct coor {
        int x;
        int y;
        bool isLeft;
}coor;

bool checkLeft(coor coord)
{
        if (coord.x < 0)
                return true;
        return false;
}

int main()
{
        int n;
        cin >> n;

        coor coords[n];

        int left = 0, right = 0;
        for (int i = 0; i < n; i++) {
                cin >> coords[i].x >> coords[i].y;
                //coords[i].isLeft = checkLeft(coords[i]);
                if (checkLeft(coords[i]))
                        left++;
                else
                        right++;
        }

        if (left == 1 || right == 1 || left == 0 || right == 0)
                cout << "Yes\n";
        else
                cout << "No\n";
        return 0;
}
