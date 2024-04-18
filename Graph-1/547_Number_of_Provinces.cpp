void dfs(int i, vector<int>&vis, std::vector<std::vector<int>>& roads) {
        
        vis[i] = 1;
        for (int j=0;j<roads[i].size();j++) {
            if(roads[i][j]==0)  continue;
            if (vis[j]==0) {
                dfs(j, vis, roads);
            }
        }
 }
int findCircleNum(vector<vector<int>>& roads) {
      int n=roads.size();
      vector<int>vis(n,0); 
      int ans = 0;
      for (int i = 0; i < n; i++) {
         if (vis[i]==0) {
         ans++;
         dfs(i, vis, roads);
      }
    }
    return ans;
 }