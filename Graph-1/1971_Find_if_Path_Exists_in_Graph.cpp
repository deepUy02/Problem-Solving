bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        unordered_map<int,vector<int>> gp; 
        for(auto i : edges) {
            gp[i[0]].push_back(i[1]);
            gp[i[1]].push_back(i[0]);
        }
        vector<bool> vis(n,0);        
        stack<int> st;
        st.push(start);
        vis[start] = 1; 
        
        while(!st.empty()){ 
            auto top = st.top();
            if(top == end)
                return 1;
            st.pop();
            for(auto node : gp[top]){
                if(!vis[node]){
                    vis[node] = 1;
                    st.push(node); 
                }
            }
        }
        return false;
    }
};