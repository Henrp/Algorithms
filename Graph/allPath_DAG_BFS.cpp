#include <iostream>
#include <vector>
#include <queue>

vector<vector<int>> ans;
    void BFS(vector<vector<int>>& graph, int src)
    {
        queue<pair<int, vector<int>>> q;
        q.push({src, {src}});
        while (!q.empty()){
            auto [curSrc, curPath] = q.front();
            q.pop();
            
            if (curSrc == graph.size()-1){
                ans.push_back(curPath);
            }
            
            for (auto node : graph[curSrc]){
                curPath.push_back(node);
                q.push({node, curPath});
                curPath.pop_back();
            }
        }
    }


	

