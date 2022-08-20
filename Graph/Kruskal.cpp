#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct graph
{
    pair<int, int> edge;
    int weight;
};

vector<graph> minst;
bool comp (graph a, graph b)
{
    return a.weight < b.weight ? true : false;
}

// DSU
vector<int> nodes;
int same(int n)
{
    return nodes[n] < 0 ? n : nodes[n] = same(nodes[n]);
}

void unite(int n1, int n2)
{
    n1 = same(n1), n2 = same(n2);
    nodes[n1] = n2;
}

int main()
{
    int n, max_node; cin >> n >> max_node;
    nodes.resize(max_node, -1);

    while (n--){
        int e1, e2, w; cin >> e1 >> e2 >> w;
        e1--; e2--;
        minst.push_back({{e1,e2}, w});
    }

    sort(minst.begin(), minst.end(), comp);

    //keep adding edges to seperated compenents
    int total_weight = 0;
    for (auto i : minst){
        if (same(i.edge.first) != same(i.edge.second)){
            total_weight += i.weight;
            unite(i.edge.first, i.edge.second);
        }
    }
    cout << total_weight;
}