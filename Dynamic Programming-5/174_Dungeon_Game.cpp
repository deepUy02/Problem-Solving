
int dp[201][201];
    int solve(int i, int j, vector<vector<int>> &dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(i == m || j == n){
            return INT_MAX;
        }
        if(i == (m - 1) && j == (n - 1)){
            return dungeon[i][j] < 0 ? -dungeon[i][j] + 1 : 1;
        }
        int rightValue = solve(i, j + 1, dungeon); // Answer for the right cell if we move right
        int downValue = solve(i + 1, j, dungeon); // Answer for the below cell if we move down
        
        int min_health_Required = min(rightValue, downValue) - dungeon[i][j];
        return dp[i][j] = min_health_Required <= 0 ? 1: min_health_Required;
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        memset(dp, -1, sizeof dp);
        return solve(0, 0, dungeon);
    }