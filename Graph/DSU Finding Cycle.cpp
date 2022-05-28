#include <iostream>
#include <vector>
using namespace std;

struct node
{
    int parent, rank;
};

vector<node> parents;

int find(int v) //find the root node of each set
{
    if (parents[v].parent == -1) return v;
    return parents[v].parent=find(parents[v].parent);
}

void unionSet(int r1, int r2) //union the root node by making one of the root into the other
{
    if (parents[r1].rank > parents[r2].rank) parents[r2].parent = r1;
    else if (parents[r1].rank < parents[r2].rank) parents[r1].parent = r2;
    else {
        parents[r1].parent = r2;
        parents[r2].rank++;
    }
}

bool isCyclic(vector<pair<int, int>> edgeList)
{
    for (auto v : edgeList){
        int r1 = find(v.first), r2 = find(v.second);
        if (r1 == r2) return true;
        unionSet(r1, r2);
    }
    return false;
}

int main()
{
    int edge, vert; cin >> edge >> vert;

    parents.resize(vert);
    for (int i = 0; i < vert; i++){
        parents[i].parent = -1;
        parents[i].rank = 0;
    }
    vector<pair<int, int>> edgeList;
    for (int i = 0; i < edge; i++){
        int from, to; cin >> from >> to;
        edgeList.push_back({from, to});
    }

    if (isCyclic(edgeList)) cout << "true";
    else cout << "false";
}
