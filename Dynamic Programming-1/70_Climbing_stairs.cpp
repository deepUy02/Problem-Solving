Approach-1(Tabulation)
int climbStairs(int n) {
        if (n == 0 || n == 1) {
            return 1;
        }
        vector<int> dp(n+1);
        dp[0] = dp[1] = 1;
        
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }

Approach-2(Optimization)
int climbStairs(int n) {
        if (n == 0 || n == 1) {
            return 1;
        }
        int prev1 = 1, prev2 = 1;
        for (int i = 2; i <= n; i++) {
            int temp = prev2;
            prev2 = prev1 + prev2;
            prev1 = temp;
        }
        return prev2;
    }
