Approach-1(Recursion)-> Gives TLE

int solve(string& word1, string& word2, int i ,int j){
        //base case
        if(i == word1.length()){
            return word2.length() - j;
        }
        if(j == word2.length()){
            return word1.length() - i;
        }

        int minimumOperations = 0;
        if(word1[i] == word2[j]){
            return solve(word1 , word2 , i+1, j+1);
        }
        else{
            //insert operation 
            int insertCharacter = 1 + solve(word1, word2, i , j+1);
            //delete operation 
            int deleteCharacter = 1 + solve(word1, word2, i+1, j);
            //replace operation
            int replaceCharacter = 1 + solve(word1, word2, i+1, j+1);
            //update minimumOperation 
            minimumOperations = min(insertCharacter , min(deleteCharacter, replaceCharacter));
        }
        return minimumOperations;
    }
int minDistance(string word1, string word2) {
   return solve(word1 , word2, 0 , 0);
}

Approach-2(Recursion + Memo)

int solve(string& word1, string& word2, int i ,int j, vector<vector<int>>&dp){
        //base case
        if(i == word1.length()){
            return word2.length() - j;
        }
        if(j == word2.length()){
            return word1.length() - i;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int minimumOperations = 0;
        if(word1[i] == word2[j]){
            return solve(word1 , word2 , i+1, j+1, dp);
        }
        else{
            //insert operation 
            int insertCharacter = 1 + solve(word1, word2, i , j+1, dp);
            //delete operation 
            int deleteCharacter = 1 + solve(word1, word2, i+1, j, dp);
            //replace operation
            int replaceCharacter = 1 + solve(word1, word2, i+1, j+1, dp);
            //update minimumOperation 
            minimumOperations = min(insertCharacter , min(deleteCharacter, replaceCharacter));
        }
        return dp[i][j] = minimumOperations;
    }
int minDistance(string word1, string word2) {
    vector<vector<int>>dp(word1.length() ,vector<int>(word2.length(), -1));
    return solve(word1 , word2, 0 , 0, dp);
}

Approach-3(Tabulation)

int solveTabulation(string a , string b){
        vector<vector<int>>dp(a.length()+1, vector<int>(b.length()+1, 0));

        for(int i = 0;i< a.length();i++){
            dp[i][b.length()] = a.length() - i;
        }
        for(int j = 0;j< b.length();j++){
            dp[a.length()][j] = b.length() - j;
        }

        for(int i = a.length()-1; i>= 0;i--){
            for(int j = b.length()-1; j>= 0; j--){
                int minimumOperations = 0;
                if(a[i] == b[j]){
                    minimumOperations = dp[i+1][j+1];
                }
                else{
                    //insert Character
                    int insertCharacter = 1 + dp[i][j+1];
                    //delete Character
                    int deleteCharacter = 1 + dp[i+1][j];
                    //repalce Character
                    int replaceCharacter = 1 + dp[i+1][j+1];
                    minimumOperations = min(insertCharacter , min(deleteCharacter, replaceCharacter));
                }
                dp[i][j] = minimumOperations;
            }
        }
        return dp[0][0];
    }
int minDistance(string word1, string word2) {
    return solveTabulation(word1 , word2);
}

Approach-4(Space Optimization)

int solve(string a , string b){
        vector<int> curr(b.length()+1,0);
        vector<int> next(b.length()+1,0);

        for(int j = 0;j< b.length();j++){
            next[j] = b.length() - j;
        }

        for(int i = a.length()-1; i>= 0;i--){
            for(int j = b.length()-1; j>= 0; j--){
                
                curr[b.length()] = a.length()-i;

                int minimumOperations = 0;
                if(a[i] == b[j]){
                    minimumOperations = next[j+1];
                }
                else{
                    //insert Character
                    int insertCharacter = 1 + curr[j+1];
                    //delete Character
                    int deleteCharacter = 1 + next[j];
                    //repalce Character
                    int replaceCharacter = 1 + next[j+1];
                    minimumOperations = min(insertCharacter , min(deleteCharacter, replaceCharacter));
                }
                curr[j] = minimumOperations;
            }
            next = curr;
        }
        return next[0];
    }
int minDistance(string word1, string word2) {
    if(word1.length()==0){
        return word2.length();
    }
    if(word2.length()==0){
       return word1.length();
    }
    return solve(word1, word2);
}