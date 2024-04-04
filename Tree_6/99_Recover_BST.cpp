
class Solution {
public:
    TreeNode* firstError;
    TreeNode* secondError;
    TreeNode* previous;

    void inorder(TreeNode* root){
        if(root == NULL)    return;

        inorder(root->left);
        if(firstError == NULL && root->val < previous->val){
            firstError = previous;
        }
        if(firstError != NULL && root->val < previous->val){
            secondError = root;
        }
         previous = root;
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        previous = new TreeNode(INT_MIN);
        inorder(root);
        swap(firstError->val, secondError->val);
    }
};