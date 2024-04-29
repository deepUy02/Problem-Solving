bool dfs(int src, int parent, vector<int> adjacent[], vector<bool>& vis) {
        vis[src] = true;
        for (auto adjnode : adjacent[src]) {
            if (!vis[adjnode]) {
                if (dfs(adjnode, src, adjacent, vis))
                    return true;
            } else if (adjnode != parent)
                return true;
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
       int n = edges.size();
        vector<int> adjacent[n + 1];
        for (int i = 0; i < n; i++) {
            adjacent[edges[i][0]].push_back(edges[i][1]);
            adjacent[edges[i][1]].push_back(edges[i][0]);
            vector<bool> visited(n + 1, false);
            if (dfs(edges[i][0], -1, adjacent, visited)) {
                return edges[i];
            }
        }
        return {}; 
    }