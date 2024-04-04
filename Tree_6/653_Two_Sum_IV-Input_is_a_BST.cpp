class Solution {
public:
    bool dfs(TreeNode*root ,int k ,unordered_map<int,int>&mp){
        if(root == NULL)    return false;

        if(mp.find(k - root->val) != mp.end())  return true;
        mp[root->val]++;
        return dfs(root->left,k,mp) || dfs(root->right,k,mp);
    }
    bool findTarget(TreeNode* root, int k) {
        if(root == NULL)    return false;
        unordered_map<int,int>mp;
        return dfs(root , k , mp);
    }
};