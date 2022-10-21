#include <bits/stdc++.h> 
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    vector<int> graph[vertex];
    for(auto it : edges){
        graph[it.first].push_back(it.second);
        graph[it.second].push_back(it.first);
    }
    
    for(int i=0;i<vertex;i++){
        sort(graph[i].begin(),graph[i].end());
    }
    
    bool vis[vertex];
    memset(vis,false,sizeof(vis));
    
    vector<int> ans;
    for(int i =0; i < vertex; i++){
        if(!vis[i]){
            queue<int> q;
            q.push(i);
            vis[i] = true;
            
            while(!q.empty()){
                int t = q.front();
                q.pop();
                ans.push_back(t);
                
                for(auto it : graph[t]){
                    if(!vis[it]){
                        q.push(it);
                        vis[it] = true;
                    }
                }
            }
        }
    }
    
    return ans;
}
