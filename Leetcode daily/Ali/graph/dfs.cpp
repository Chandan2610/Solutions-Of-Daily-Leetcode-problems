void dfs(vector<int> graph[], int v, bool vis[], vector<int> &temp){
    vis[v] = true;
    temp.push_back(v);
    
    for(auto it : graph[v]){
        if(!vis[it])
            dfs(graph,it,vis,temp);
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    vector<int> graph[V];
    
    for(auto it : edges){
        graph[it[0]].push_back(it[1]);
        graph[it[1]].push_back(it[0]);
    }
    
    bool vis[V];
    memset(vis,false,sizeof(vis));
    vector<vector<int>> ans;
    
    for(int i = 0;i<V;i++){
        if(!vis[i]){
            vector<int> temp;
            dfs(graph,i,vis,temp);
            ans.push_back(temp);
        }
    }
    
    return ans;
}
