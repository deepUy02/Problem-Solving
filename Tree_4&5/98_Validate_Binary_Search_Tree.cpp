class Solution {
public:
    bool checkBST(TreeNode* root,long min=LONG_MIN,long max=LONG_MAX){
        //base case
        if(root==NULL)  return true;

        if(root->val>min && root->val<max){
            bool left=checkBST(root->left,min,root->val);//check for left of the Tree
            bool right=checkBST(root->right,root->val,max);//check for right of the Tree
            return left && right;//if both true then return true
        }
        else    return false;
    }
    bool isValidBST(TreeNode* root) {
        return checkBST(root);
    }
};