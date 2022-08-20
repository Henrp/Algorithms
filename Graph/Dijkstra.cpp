#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
    int n, e; cin >> n >> e; //node and edge
    vector<pair<int, int>> adj(n); //destination node and weight
    priority_queue<pair<int, int>> q;

    for (int i = 0; i < e; i++){
        int s_n, d_n, weight; cin >> s_n >> d_n >> weight; 
        //s_n--, d_n--;

        adj[s_n] = {d_n, weight}; 
    }
    vector<int> distance (n, INT_MAX); //distance from node 0
    distance[0] = 0;
    q.push({0, 0}); //distance and minimum (starting) node

    while (!q.empty()){
        int a = q.top().second; q.pop();
        for (int u : adj[a]){
            int b = u.first, w = u.second;
            if (distance[a]+w < distance[n]){
                distance[b] = distance[a]+w;
                q.push({-distance[b], b});
            }
        }
    }

    for (int i = 1; i < n; i++){
        cout << distance[i] << " ";
    }
}
