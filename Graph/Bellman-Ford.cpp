#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int main()
{
    int n, e; cin >> n >> e;
    vector<tuple<int, int, int>> edges;
    vector<int> distance (n, INT_MAX);
    distance[0] = 0;

    for (int i = 0; i < e; i++){
        int a, b, w; cin >> a >> b >> w; a--, b--;
        edges.push_back({a,b,w});
    }

    for (int i = 0; i < n-1; i++){
        for (auto e : edges){
            int a, b, w;
            tie(a,b,w) = e;
            distance[b] = min(distance[b], distance[a]+w);
        }
    }

    //all minimum distance from node 1 (0);
    /*
    for (int i : distance){
        cout << i << "\n";
    }
    */

    //negative cycle
    
}