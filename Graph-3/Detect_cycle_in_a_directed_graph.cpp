bool dfs(int nd,vector<int>adj[],int vis[],int pathvis[])
    {
        vis[nd] = 1;
        pathvis[nd] = 1;
        for(auto i:adj[nd])
        {
            if(vis[i]==0)
            {
                if(dfs(i,adj,vis,pathvis)==true)
                    return true;
            }
            else if(pathvis[i])
                return true;
        }
        pathvis[nd]=0;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        int vis[V]={0};
        int pathvis[V]={0};
        
        for(int i = 0; i < V; i++)
        {
            if(!vis[i])
            {
                if(dfs(i,adj,vis,pathvis)==true)
                    return true;
            }
        }
        return false;
    }