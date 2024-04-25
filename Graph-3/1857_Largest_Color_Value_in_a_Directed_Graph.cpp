int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<int> adjcnt[n];
        
        unordered_map<int,int> indgr;
        for(vector<int>&v : edges){
            adjcnt[v[0]].push_back(v[1]);
            indgr[v[1]]++;
        }
        queue<int> qu;
        vector<vector<int>> dp(n,vector<int> (26,0));
        for(int i=0;i<n;i++){
            if(indgr[i] == 0) {
                qu.push(i);
                dp[i][colors[i] - 'a'] = 1;
            }
        }
        int visNodes = 0;
        while(!qu.empty()){
            int node = qu.front();
            qu.pop();
            visNodes++;
            for(int child : adjcnt[node]){
                for(int i=0;i<26;i++){
                    dp[child][i] = max(dp[child][i],dp[node][i] + (i == (colors[child] - 'a')));
                }
                indgr[child]--;
                if(indgr[child] == 0) qu.push(child);
            }
        }
        if(visNodes < n) return -1; 
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int clr=0;clr<26;clr++){
                ans = max(ans,dp[i][clr]);
            }
        }
        return ans;
    }