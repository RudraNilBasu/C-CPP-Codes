#include <stdio.h>
#include <map>
#include <vector>

using namespace std;

int main()
{
        int n;
        scanf("%d", &n);
        int a[n];
        map<int, int> freq;
        vector<int> distinct_cards;

        int i;

        for (i = 0; i < n; i++) {
                scanf("%d", a + i);

                if (freq[ a[i] ] == 0) {
                        distinct_cards.push_back( a[i] );
                }
                freq[ a[i] ]++;
        }
        if (distinct_cards.size() == 2 && (freq[ distinct_cards[0] ] == freq[ distinct_cards[1] ]) ) {
                printf("YES\n%d %d\n", distinct_cards[0], distinct_cards[1]);
        } else {
                printf("NO\n");
        }
        return 0;
}
