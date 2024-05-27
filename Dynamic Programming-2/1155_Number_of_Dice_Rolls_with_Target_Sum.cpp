//USING RECURSION
int mod = 1e9+7;
    int solveRecursion(int n ,int k ,int target){
        if(target < 0){
            return 0;
        }   
        if(n == 0)  return (target == 0);

        int ways = 0;
        for(int i = 1;i <= k;i++){
            ways = (ways + solveRecursion(n-1,k,target-i))%mod;
        }
        return ways;    
}    
int numRollsToTarget(int n, int k, int target) {
    return solveRecursion(n, k ,target);
}

//USING RECURSION + MEMO
int solveRecursion(int n ,int k ,int target,vector<vector<int>> &dp){
        if(target < 0){
            return 0;
        }
        if(dp[n][target] != -1) return dp[n][target];
       
        if(n == 0)  return (target == 0);

        int ways = 0;
        for(int i = 1;i <= k;i++){
            ways = (ways + solveRecursion(n-1,k,target-i,dp))%mod;
        }
        return dp[n][target] = ways;
}
int numRollsToTarget(int n, int k, int target) {
    vector<vector<int>> dp(31,vector<int>(1001,-1));
    return solveRecursion(n, k ,target,dp);
}

//USING BOTTOM UP
int mod = 1e9+7;
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n+1,vector<int>(target+1));

        dp[0][0] = 1;

        for(int i = 1;i < n+1;i++){//i---->n
            for(int j = 1;j < target+1;j++){//j--->target
                int ways = 0;
                for(int face = 1;face <= k;face++){
                    if(j >= face){
                        ways = (ways + dp[i-1][j-face]) % mod;
                    }
                }
                dp[i][j] = ways;
            }
        }

        return dp[n][target];
    }