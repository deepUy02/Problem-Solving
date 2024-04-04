class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        //base case
        if(root == NULL)    return 0;

        if(root->val >= low && root->val <= high){
            int left = rangeSumBST(root->left , low , high);
            int right = rangeSumBST(root->right , low , high);
            return root->val + left + right;
        }
        
        if(root->val < low){
            return rangeSumBST(root->right , low , high);
        }
        return rangeSumBST(root->left , low , high);
    }
};