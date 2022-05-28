#include <iostream>
#include <vector>
using namespace std;

vector<int> parents;
int find(int v) //find the root node of each set
{
    if (parents[v] == -1) return v;
    return find(parents[v]);
}

void unionSet(int r1, int r2) //union the root node by making one of the root into the other
{
    parents[r1] = r2;
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

    parents.resize(vert, -1);

    vector<pair<int, int>> edgeList;
    for (int i = 0; i < edge; i++){
        int from, to; cin >> from >> to;
        edgeList.push_back({from, to});
    }

    if (isCyclic(edgeList)) cout << "true";
    else cout << "false";
}