#include <bits/stdc++.h> 

void dfs(vector<int> graph[], int u,stack<int> &ans,vector<bool> &vis){
    vis[u] = true;
    
    for(auto it : graph[u]){
        if(!vis[it])
            dfs(graph,it,ans,vis);
    }
    ans.push(u);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    vector<int> graph[v];
    vector<bool> vis(v,false);
    
    for(auto it : edges){
        graph[it[0]].push_back(it[1]);
    }
    
    stack<int> ans;
    
    for(int i=0;i<v;i++){
        if(!vis[i])
            dfs(graph,i,ans,vis);
    }
    
    vector<int> answer;
    
    while(!ans.empty()){
        int t = ans.top();
        ans.pop();
        answer.push_back(t);
    }
    return answer;
}
