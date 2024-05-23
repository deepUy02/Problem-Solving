Approach-1(Recursion)
long long int solve(vector<int>&nums, int start, int end){
        if(start >= end) return 0;
        long  long int minimumJumps = INT_MAX;

        for(int i = 1;i <= nums[start];i++){
            minimumJumps = min(minimumJumps, 1 + solve(nums, start + i, end));
        }
        return minimumJumps;
    }
int jump(vector<int>& nums) {
	return solve(nums, 0 ,nums.size()-1 );
}

Approach-2(Recursion + Menmo)

long long int solve(vector<int>&nums, int start, int end,vector<int>&dp){
        if(start >= end) return 0;
        if(dp[start] != -1) return dp[start];

        long  long int minimumJumps = INT_MAX;

        for(int i = 1;i <= nums[start];i++){
            if(1+start > end)   break;
            minimumJumps = min(minimumJumps, 1 + solve(nums, start + i, end,dp));
        }
        return dp[start] = minimumJumps;
}
int jump(vector<int>& nums) {
    vector<int>dp(nums.size() + 1, -1);
    return solve(nums, 0 ,nums.size()-1 ,dp);
}

Approach-3(Tabulation)


Approach-4(Space Optimization)

int jump(vector<int>& nums) {
        
        for(int i = 1;i < nums.size();i++){
            nums[i] = max(nums[i]+i , nums[i-1]);
        }
        int jumps = 0;
        int j = 0;
        while(j < nums.size()-1){
            jumps++;
            j = nums[j];
        }
        return jumps;
}