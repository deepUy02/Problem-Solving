//USING RECURSION
int solveRecursion(int index , string &s ,int n){
    if(index == n){
        return 1;        
    }
    if(s[0] == '0'){
       return 0;
    }

    int one_char_taken = solveRecursion(index + 1, s, n);
    int two_char_taken = 0;
    if(index + 1 < n){
       if(s[index] == '1' || (s[index] == '2' && s[index + 1] <= '6')){
          two_char_taken = solveRecursion(index + 2, s, n);
       }
    }
    return one_char_taken + two_char_taken;
}
int numDecodings(string s) {
    int n = s.length();
    return solveRecursion(0 ,s , n);
}

//USING RECURSION + MEMO

int solveRecursion(int index , string &s , int n , vector<int>&dp){

    if(index == n){
       return 1;
    }
    if(s[index] == '0'){
       return 0;
    }
    if(dp[index] != -1) 
       return dp[index];
    int one_char_taken = solveRecursion(index + 1, s, n , dp);
    int two_char_taken = 0;
        
    if(index + 1 < s.size() && (s[index] == '1' || (s[index] == '2' && s[index + 1] <= '6'))){
       two_char_taken = solveRecursion(index + 2, s, n , dp);
    }

    return dp[index] = one_char_taken + two_char_taken;
}
int numDecodings(string s) {
    int n = s.size();
    vector<int>dp(n+1,-1);
    return solveRecursion(0 ,s , n, dp);
}

//USING BOTTOM UP 
int numDecodings(string s) {
    vector<int>dp(s.length()+1,0);

    dp[s.length()] = 1;

    for(int i = s.length()-1 ; i>=0 ; i--){
        if(s[i] == '0'){
           dp[i] = 0;
        }
        else{
           dp[i] = dp[i+1];
           if(i+1 < s.length()){
              if(s[i] == '1' || (s[i] == '2' && s[i+1] <= '6')){
                 dp[i] += dp[i+2];
              }
           }
        }
     }
   return dp[0];
}
