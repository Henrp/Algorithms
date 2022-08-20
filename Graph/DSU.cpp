#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> nodes;

int node_num(int n)
{
    return nodes[n] < 0 ? n : nodes[n] = node_num(nodes[n]);
}

int size(int n)
{
    return -nodes[get(n)];
}

void unite(int a, int b)
{
    a = node_num(a), b = node_num(b);
    if (a != b){
        if (nodes[a] > nodes[b]) swap(a, b);
        nodes[a] += nodes[b]; nodes[b] = a; 
    }
}

int main()
{   
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, q; cin >> n >> q;
    nodes.resize(n, -1);
    for (int i = 0; i < q; i++){
        int t, u, v; cin >> t >> u >> v;
        if (t == 0){
            unite(u, v);
        } else {
            if (node_num(u) == node_num(v)) cout << 1 << "\n";
            else cout << 0 << "\n";
        }
    }
}