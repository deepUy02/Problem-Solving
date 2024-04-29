vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};
    bool isValid(int i, int j, int m, int n){
        return ((i >= 0 && i < m) && (j >= 0 && j < n));
    }
    int minimumEffortPath(vector<vector<int>>& h) {
        int m = h.size();
        int n = h[0].size();
        vector<vector<int>> dis(m, vector<int>(n, INT_MAX));
        using p = pair<int, pair<int, int>>;
        priority_queue<p, vector<p>, greater<p>> pq;
        dis[0][0] = 0;
        pq.push({0, {0, 0}});
        while(pq.size()){
            auto [effort, tmp] = pq.top();
            int i = tmp.first, j = tmp.second;
            if(i == m - 1 && j == n - 1)
                return dis[m - 1][n - 1];
            pq.pop();
            for(int k = 0 ; k < 4 ; k++){
                int x = dx[k] + i, y = dy[k] + j;
                if(isValid(x, y, m, n)){
                    int maxi = max(effort, abs(h[x][y] - h[i][j]));
                    if(maxi < dis[x][y]){
                        dis[x][y] = maxi;
                        pq.push({maxi, {x, y}});
                    }
                }
            }
        }
        return 0;
    }