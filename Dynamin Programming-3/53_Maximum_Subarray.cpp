Approach-1 
int maxSubArray(vector<int>& nums) {
    int sum=0;
    int maxi=nums[0];
    for(int i=0;i<nums.size();i++)
       {
        sum+=nums[i];
        maxi=max(maxi,sum);
        if(sum<0)
          sum=0;
       }
    return maxi;
}

Approach-2
int maxSubArray(vector<int>& nums) {
    int n=nums.size();
    int maximumSum=INT_MIN,currSumSubarray=0;
    for(int i=0;i<n;i++)
       {
        currSumSubarray+=nums[i];
        maximumSum=max(maximumSum,currSumSubarray);
        currSumSubarray=max(currSumSubarray,0);
       }
    return maximumSum;
}