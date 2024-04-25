void dfs(int node, vector<int> &vis, vector<vector<int>>& adj,
        stack<int> &st) {
        vis[node] = 1;
        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfs(it, vis, adj, st);
            }
        }

        st.push(node);
    }
    void dfs1(int node, vector<int> &vis, vector<vector<int>>& adjT) {
        vis[node] = 1;
        for (auto it : adjT[node]) {
            if (!vis[it]) {
                dfs1(it, vis, adjT);
            }
        }
    }
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        vector<int> visited(V, 0);
        stack<int> st;
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(i, visited, adj, st);
            }
        }

        vector<vector<int>> adj_T(V);
        for (int i = 0; i < V; i++) {
            visited[i] = 0;
            for (auto &it : adj[i]) {
                adj_T[it].push_back(i);
            }
        }
        int count = 0;
        while (!st.empty()) {
            int node = st.top();
            st.pop();
            if (!visited[node]) {
                count++;
                dfs1(node, visited, adj_T);
            }
        }
        return count;
    }