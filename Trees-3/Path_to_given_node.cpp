bool path(TreeNode* root , int key , vector<int>& res){
    if(root == NULL){
        return false;
    }
    if(root->val == key || path(root->left , key , res) || path(root->right , key , res )){
        res.push_back(root->val);
        return true;
    }
    return false;
}
vector<int> Solution::solve(TreeNode* root, int b) {
    vector<int> res;
    path(root , b , res);
    reverse(res.begin(),res.end());
    return res;
}