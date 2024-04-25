bool solve(int s,int x,vector<int> &visted,vector<vector<int>> &g)
    {
        if(visted[s]!=-1)
        {
            if(visted[s] != x)return false;
            return true;
        }
        visted[s] = x;
        bool ans = true;
        for(auto &i: g[s])
        {
            ans &= solve(i,x^1,visted,g);
        }
        return ans;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size(),i;
        vector<int> visted(n,-1);
        vector<vector<int>> g(n);
        for(i = 0; i < n; i++)
        {
            for(auto &t: graph[i])
            {
                g[i].push_back(t);
            }
        }
        bool ans = true;
        for(i = 0; i < n; i++)
        {
            if(visted[i]==-1)
            {
                ans &= solve(i,0,visted,g);
            }
        }
        return ans;
    }