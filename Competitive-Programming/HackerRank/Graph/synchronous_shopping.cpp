#include<stdio.h>
#include<limits.h>
#include<vector>
#include<set>
//#include<pair>

#define MAX_SHOP 1001
#define MAX_FISH_TYPE (1030)
using namespace std;

typedef struct node{
    int dest;
    int cost;
}node;

int shortest_path[MAX_SHOP][MAX_FISH_TYPE];
                        // shortest_path[i][mask] shortest path from shop 1 to shop i
                        // covering "mask" types of fish
                        // "mask" - bitmask representation
int shops[MAX_SHOP];
                // stores the "mask" of the types of fish
                // in the ith shop

vector<node> graph[MAX_SHOP];
set< pair<int, pair<int,int> > > queue;
int reset()
{
    int i,j;
    for(i=0;i<MAX_SHOP;i++) {
        for(j=0;j<MAX_FISH_TYPE;j++) {
            shortest_path[i][j]=INT_MAX/2;
        }
        shops[i]=0;
    }
    return 0;
}

void Qinsert(int src, int mask, int cost)
{
    if( shortest_path[src][mask] <=cost ) {
        // current path is longer that already
        // calculated path
        return;
    }


    // check if it already exists or not
    pair<int, pair<int,int> > current = make_pair(shortest_path[src][mask], make_pair(src, mask));

    set< pair<int, pair<int,int> > > ::iterator it;
    it = queue.find(current);
    if(it!=queue.end()) {
        queue.erase(it);
    }

    shortest_path[src][mask]=cost;
    current.first=cost;
    queue.insert(current);
}

void Dijksktra(int src)
{
    Qinsert(src, shops[1], 0);
    while(!queue.empty()) {
        int cost = queue.begin()->first;
        int shop_covered = queue.begin()->second.second; // mask of the shops covered

        int current_shop,i;
        current_shop = queue.begin()->second.first; // neighbouring c
        queue.erase(queue.begin());
        for(i=0;i<graph[current_shop].size();i++) {
            Qinsert(graph[current_shop][i].dest, shop_covered | shops[graph[current_shop][i].dest], cost+graph[current_shop][i].cost );
        }
    }
}

int main()
{
    int n_shops, n_roads, n_fishtypes;
    int i,j,t,x,ans;
    scanf("%d %d %d",&n_shops, &n_roads, &n_fishtypes);

    reset();

    for(i=1;i<=n_shops;i++) {
        int mask=0;
        scanf("%d",&t);
        while(t--) {
            scanf("%d",&x);
            mask = mask | (1<<(x-1));
            // calculating the union of all the types of fish found
            // in the ith shop
        }
        shops[i]=mask;
    }

    // input of graph
    for(i=0;i<n_roads;i++) {
        int src, dest, cost;
        scanf("%d %d %d",&src, &dest, &cost);
        node temp;
        temp.dest=dest;
        temp.cost=cost;
        graph[src].push_back(temp);
        temp.dest=src;
        graph[dest].push_back(temp);
    }

    /*
    for(i=1;i<n_shops;i++) {
        printf("%d ->",i);
        for(j=0;j<graph[i].size();j++) {
            printf("%d, ",graph[i][j]);
        }
        printf("\n");
    }
    */

    Dijksktra(1); // essentially to fillup shortest_path[i][mask]
                    // which will calculate the shortest path to
                    // reach shop i buying "mask" no of fishes
                    // starting from shop 1

    ans=INT_MAX;
    for(i=0;i<(1<<n_fishtypes);i++) {
        for(j=i;j<(1<<n_fishtypes);j++) {
            if( (i|j) ==  (1<<n_fishtypes)-1 ) {
                ans = min(ans, max(shortest_path[n_shops][i], shortest_path[n_shops][j]));
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
