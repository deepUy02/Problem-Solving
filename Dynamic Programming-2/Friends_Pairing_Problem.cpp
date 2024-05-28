//USING RECURSION 
long long int solveRecursion(int n){
    if(n <= 2)  return n;
        
    long long int single_pair = solveRecursion(n-1) % mod;
    long long int coupled_pair = (((n-1)%mod) * solveRecursion(n-2)%mod) % mod;
        
    return single_pair + coupled_pair;
}
int countFriendsPairings(int n) 
{
  return solveRecursion(n)%mod;
}

//USING RECURSION + MEMO

long long int solveRecursion(int n , vector<long long int>&dp){
     if(n <= 2)  return n;
     if(dp[n] != -1) return dp[n];
        
     long long int single_pair = solveRecursion(n-1, dp) % mod;
     long long int coupled_pair = (((n-1)%mod) * solveRecursion(n-2, dp)%mod) % mod;
        
     return dp[n] = single_pair + coupled_pair;
}
int countFriendsPairings(int n) 
{ 
     vector<long long int>dp(n+1,-1);
     return solveRecursion(n , dp)%mod;
}

//BOTTOM_UP
int countFriendsPairings(int n) 
  { 
     vector<long long int>dp(n+1,0);
     dp[0] = 0;
     dp[1] = 1;
     dp[2] = 2;
     for(long long int i  = 3;i <= n ;i++ ){
         dp[i] = ((dp[i-1]) % mod + (((i-1) % mod) * (dp[i-2]) % mod))% mod;
     }
     return dp[n];
}
    