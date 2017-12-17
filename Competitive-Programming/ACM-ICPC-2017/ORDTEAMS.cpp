#include <stdio.h>
#include <iostream>

using namespace std;

typedef struct student {
        int hardwork;
        int intelligence;
        int persistence;
}student;

bool isBetter(student s1, student s2)
{
                        if (s1.hardwork < s2.hardwork) return false;
      if (s1.intelligence < s2.intelligence) return false;
      if (s1.persistence < s2.persistence) return false;
      
      if (s1.hardwork > s2.hardwork) return true;
      if (s1.intelligence > s2.intelligence) return true;
      if (s1.persistence > s2.persistence) return true;
      
      return false;
}

int check()
{
        student s[3];
        cin >> s[0].hardwork >> s[0].intelligence >> s[0].persistence;
        cin >> s[1].hardwork >> s[1].intelligence >> s[1].persistence;
        cin >> s[2].hardwork >> s[2].intelligence >> s[2].persistence;

        if (isBetter(s[0], s[1]) && isBetter(s[0], s[2]) && (isBetter(s[1], s[2]) || isBetter(s[2], s[1]))) {
                cout << "yes\n";
                return 0;
        }
        if (isBetter(s[1], s[0]) && isBetter(s[1], s[2]) && (isBetter(s[0], s[2]) || isBetter(s[2], s[0]))) {
                cout << "yes\n";
                return 0;
        }
        if (isBetter(s[2], s[0]) && isBetter(s[2], s[1]) && (isBetter(s[0], s[1]) || isBetter(s[1], s[0]))) {
                cout << "yes\n";
                return 0;
        }
        cout << "no\n";
        return 0;
}

int main()
{
        int t;
        scanf("%d", &t);
        while (t--) {
                check();
        }
        return 0;
}