//USING RECURSION 
int solveRecursion(int index ,vector<int>&coins ,int amount){
     //base case
    if(index == 0){
       if(amount % coins[0] == 0)  return amount / coins[0];
         return 1e9;
       }
       int not_taken = 0 + solveRecursion(index - 1,coins , amount);
       int taken = INT_MAX;
       if(coins[index] <= amount){
           taken = 1 + solveRecursion(index , coins, amount - coins[index]);
       }
       return min(taken , not_taken);
}
int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    int result = solveRecursion(n-1 ,coins , amount);
    if(result >= 1e9)   return -1;
      return result;
}

//USING RECURSION + MEMO
int solveRecursion(int index ,vector<int>&coins ,int amount,vector<vector<int>>&dp){
    //base case
    if(index == 0){
       if(amount % coins[0] == 0)  return amount / coins[0];
         return 1e9
    }
    if(dp[index][amount] != -1) return dp[index][amount];

    int not_taken = 0 + solveRecursion(index - 1,coins , amount,dp);
    int taken = INT_MAX;
    if(coins[index] <= amount){
       taken = 1 + solveRecursion(index , coins, amount - coins[index],dp);
    }
    return dp[index][amount] = min(taken , not_taken);
}
int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    vector<vector<int>>dp(n , vector<int>(amount + 1, -1));
    int result = solveRecursion(n-1 ,coins , amount,dp);
    if(result >= 1e9)   return -1;
      return result;
}

//USING TABULATION
int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    vector<vector<int>>dp(n , vector<int>(amount + 1, 0));

    for(int amt = 0; amt <= amount;amt++){
        if(amt % coins[0] == 0) dp[0][amt] = amt / coins[0];
        else dp[0][amt] = 1e9;
    }
    for(int index = 1;index <n;index++){
       for(int target = 0; target <= amount ; target++){
          int not_taken = 0 + dp[index-1][target];
          int taken = INT_MAX;
          if(coins[index] <= target){
            taken = 1 + dp[index][target - coins[index]];
          }
          dp[index][target] = min(not_taken ,taken);
       }
    }
    int result = dp[n-1][amount];
    if(result >= 1e9)   return -1;
    return result;
 } 