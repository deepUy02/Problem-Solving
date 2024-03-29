Approach-1
TC:-O(N^2)
SC:-O(1)
int ans=0;
int pathSum(TreeNode* root, int targetSum) {
        if(root == NULL)    return 0;

        findPathSum(root,targetSum,0);
        pathSum(root->left,targetSum);
        pathSum(root->right,targetSum);
        return ans;
    }
void findPathSum(TreeNode* root,int sum,long long currSum){
        if(root==NULL)  return;
        currSum += root->val;

        if(currSum == sum){
            ans++;
        }
        findPathSum(root->left,sum,currSum);
        findPathSum(root->right,sum,currSum); 
}

Approach-2
TC:-O(N)
class Solution {
    int ans=0;
public:
    int pathSum(TreeNode* root, int targetSum) {
        if(root == NULL)    return 0;
        unordered_map<long,int>mp;
        mp[0]=1;

        findPathSum(root,0,targetSum,mp);
       
        return ans;
    }
    void findPathSum(TreeNode* root,long long currSum,int target,unordered_map<long,int>&mp){
        if(root==NULL)  return;
        currSum += root->val;
        
        if(mp.find(currSum - target)!=mp.end()){
            ans += mp[currSum - target];
        }
        mp[currSum]++;

        findPathSum(root->left,currSum ,target,mp);
        findPathSum(root->right,currSum,target,mp);
        mp[currSum]--;
        return;
    }
};