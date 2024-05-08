Approach-1: Using recursion but get TLE only 22/55 test cases pass
     int solveRecursion(int prev,int curr,vector<int>& arr){
         if(curr==arr.size()){
             return 0;
         }
         int first=0;
         if(prev==-1 || arr[prev]<arr[curr]){
             first=1+solveRecursion(curr,curr+1,arr);
         }
         int sec=solveRecursion(prev,curr+1,arr);
         return max(first,sec);
    }
     int lengthOfLIS(vector<int>& nums) {
         return solveRecursion(-1,0,nums);
     }

Approach-2: Recursion + Memoization
     int solveMemo(int prev,int curr,vector<int>& arr,int **dp){
         if(curr==arr.size()){
             return 0;
         } 
         if(prev!=-1 && dp[prev][curr]!=-1){
             return dp[prev][curr];
         }
         int first=0;
         if(prev==-1 || arr[prev]<arr[curr]){
             first=1+solveMemo(curr,curr+1,arr,dp);
         }
         int sec=solveMemo(prev,curr+1,arr,dp);
         if(prev!=-1){
             return dp[prev][curr]=max(first,sec);
         }else
             return max(first,sec);
     }
     int lengthOfLIS(vector<int>& nums) {
         int k=nums.size();
         int **ans = new int*[k+1];
	     for(int i = 0; i <= k; i++) {
	 	    ans[i] = new int[k+1];
	 	    for(int j = 0; j <= k; j++) {
	 	    	ans[i][j] = -1;
	 	    }
	     }
       return solveMemo(-1,0,nums,ans);
     }

Approach-3: Tabulation
     int lengthOfLIS(vector<int>& nums) {
         int n=nums.size();
         vector<int> dp(n,0);
         dp[0]=1;
         int ans=1;
         for(int i=1;i<n;i++){
             for(int j=i-1;j>=0;j--){
                 if(nums[j]<nums[i] && dp[i]<dp[j]){
                     dp[i]=dp[j];
                 }
             }
            dp[i]++;
             ans=max(ans,dp[i]);
         }
         return ans;
     }

Approach-4:- Binary Search 
    int lengthOfLIS(vector<int>& nums) {
        vector<int> v;
        for (int i = 0; i < nums.size(); i++) {
            auto l = lower_bound(v.begin(), v.end(), nums[i]);
            if ((l - v.begin()) == v.size()) 
                v.push_back(nums[i]);
            else v[(l - v.begin())] = nums[i];
        }
        return v.size();
    }