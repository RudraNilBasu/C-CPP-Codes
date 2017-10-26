#include <iostream>

using namespace std;

typedef struct doc {
        int s;
        int d;
}doc;

bool doc_available_today(int current_day, doc current_doc)
{
        return (current_day >= current_doc.s) && ((current_day - current_doc.s) % current_doc.d == 0);
}

int main()
{
        int n;
        cin >> n;
        int i;

        doc docs[n];
        for (i = 0; i < n; i++)
                cin >> docs[i].s >> docs[i].d;

        int days = 1, doc_to_visit = 1;
        while (doc_to_visit <= n) {
                //cout << "Day: " << days << " next doc to visit: " << doc_to_visit << endl;
                if (doc_available_today(days, docs[doc_to_visit - 1])) {
                        doc_to_visit++;
                        //cout << "Visited" << endl;
                }
                days++;
        }

        cout << (days - 1) << endl;
        return 0;
}
