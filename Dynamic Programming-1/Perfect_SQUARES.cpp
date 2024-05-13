Approach-1(Recursion)

Approach-2(Rec + Memo)
int solveMemorization(int n,vector<int>&dp){
        if(n == 0)  return 0;
        if(dp[n] != -1) return dp[n];

        int minimumCount = INT_MAX;
        for(int i = 1; i*i <= n ;i++){
            int ans = 1 + solveMemorization(n - i*i,dp);
            minimumCount = min(minimumCount , ans);
        }
        return dp[n] = minimumCount;
    }
int numSquares(int n) {
    vector<int>dp(n+1,-1);
    return solveMemorization(n,dp);  
}

Approach-3(Bottom-up)
int numSquares(int n){
    vector<int>dp(n+1,INT_MAX);

    dp[0] = 0;

    for(int i = 1;i <= n ;i++){
       for(int j = 1;j*j <= i;j++){
           dp[i] = min(dp[i], 1+dp[i - j*j]);
       }
    }
    return dp[n];   
}
