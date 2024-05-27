//USING RECURSION
    long long solveRecursion(vector<vector<int>>&questions,int idx){
        int n = questions.size();
        if(idx >= n)
            return 0;
        
        long long taken = questions[idx][0] + solveRecursion(questions ,idx + questions[idx][1]+1);
        long long not_taken = solveRecursion(questions , idx+1);
        return max(taken, not_taken);

    }
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        return solveRecursion(questions, 0);
    }

    // //USING RECURSION + MEMO
    long long solveMEMO(vector<vector<int>>&questions,int idx, vector<long long>&dp){
        int n = questions.size();
        if(idx >= n)
            return 0;
        if(dp[idx] != -1)   return dp[idx];
        long long taken = questions[idx][0] + solveMEMO(questions ,idx + questions[idx][1]+1,dp);
        long long not_taken = solveMEMO(questions , idx+1,dp);
        return dp[idx] = max(taken, not_taken);

    }
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long >dp(n+1,-1);
        return solveMEMO(questions, 0,dp);
    }

    //USING BOTTOM UP
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        if(n == 1)  return questions[0][0];
        vector<long long >dp(200001,0);

        for(int i = n-1;i>= 0;i--){
            dp[i] = max(questions[i][0] + dp[i+questions[i][1]+1], dp[i+1]);
        }
        return dp[0];
    }