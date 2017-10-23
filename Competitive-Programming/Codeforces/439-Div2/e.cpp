#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

typedef struct coord {
        int x;
        int y;
}coord;

class Barrier {
        public:
        coord corner_1;
        coord corner_2;

        int min_x;
        int max_x;

        int min_y;
        int max_y;

        Barrier() {}

        Barrier(coord corner_1, coord corner_2)
        {
                this->corner_1 = corner_1;
                this->corner_2 = corner_2;

                min_x = min(corner_1.x, corner_2.x);
                max_x = max(corner_1.x, corner_2.x);
                min_y = min(corner_1.y, corner_2.y);
                max_y = max(corner_1.y, corner_2.y);
        }

        bool operator == (Barrier const &obj)
        {
                return (is_points_equal(corner_1, obj.corner_1) && is_points_equal(corner_2, obj.corner_2)) || (is_points_equal(corner_1, obj.corner_2) && is_points_equal(corner_2, obj.corner_1));
        }

        bool is_points_equal(coord pt1, coord pt2)
        {
                return (pt1.x == pt2.x) && (pt1.y == pt2.y);
        }

        bool is_point_inside(coord pt)
        {
                return (pt.x >= min_x && pt.x <= max_x) && (pt.y >= min_y && pt.y <= max_y);
        }
};

int main()
{
#ifdef LOCAL
        freopen("input.txt", "r", stdin);
#endif
        int n, m, q;
        cin >> n >> m >> q;
        vector<Barrier> barriers;

        int ch;
        coord pt1, pt2;
        while (q--) {
                cin >> ch >> pt1.x >> pt1.y >> pt2.x >> pt2.y;
                if (ch == 1) {
                        // creating barriers
                        Barrier barrier(pt1, pt2);
                        barriers.push_back(barrier);
                } else if (ch == 2) {
                        // removing barriers
                        for (int i = 0; i < barriers.size(); i++) {
                                Barrier current_barrier = barriers[i];
                                Barrier given_barrier = Barrier(pt1, pt2);
                                if (current_barrier == given_barrier) {
                                        barriers.erase(barriers.begin() + i);
                                        i--;
                                }
                        }
                } else {
                        // walk
                        int flag = 0;
                        for (int i = 0; i < barriers.size(); i++) {
                                bool val_1, val_2;
                                val_1 = barriers[i].is_point_inside(pt1);
                                val_2 = barriers[i].is_point_inside(pt2);

                                if (val_1 != val_2) {
                                        flag = 1;
                                        break;
                                }
                        }
                        if (flag) {
                                cout << "No\n";
                        } else {
                                cout << "Yes\n";
                        }
                }
        }
        return 0;
}
