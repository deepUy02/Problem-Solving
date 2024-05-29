//USING RECURSION 
int solveRecursion(int index, int amount, vector<int>&coins){
    if(index == 0) {
        return (amount % coins[0] == 0);
     }

     int not_taken = solveRecursion(index-1, amount, coins);
     int taken = 0;
     if(coins[index] <= amount){
        taken = solveRecursion(index, amount-coins[index], coins);
     }
     return taken + not_taken;
}
int change(int amount, vector<int>& coins) {
    int n = coins.size();
    return solveRecursion(n-1,amount,coins);
}

//USING RECURSION + MEMO
int solveRecursion(int index, int amount, vector<int>&coins, vector<vector<int>>&dp){
    if(index == 0) {
       return (amount % coins[0] == 0);
    }
    if(dp[index][amount] != -1) return dp[index][amount];

    int not_taken = solveRecursion(index-1, amount, coins, dp);
    int taken = 0;
    if(coins[index] <= amount){
       taken = solveRecursion(index, amount-coins[index], coins ,dp);
    }
    return dp[index][amount] = taken + not_taken;
}
int change(int amount, vector<int>& coins) {
    int n = coins.size();
    vector<vector<int>>dp(n,vector<int>(amount+1,-1));
    return solveRecursion(n-1,amount,coins,dp);
}

//USING BOTTOM-UP
int change(int amount, vector<int>& coins) {
    int n = coins.size();
    vector<vector<int>>dp(n,vector<int>(amount+1,0));
    for(int target = 0;target <= amount;target++){
        dp[0][target] = (target % coins[0] ==0);
    }
    for(int index = 1;index < n;index++){
        for(int target = 0;target <= amount;target++){
            int not_taken = dp[index -1][target];
            int taken = 0;
            if(coins[index]<= target){
               taken = dp[index][target-coins[index]];
            }
            dp[index][target] = taken + not_taken;
	}
     }
     return dp[n-1][amount];
}
