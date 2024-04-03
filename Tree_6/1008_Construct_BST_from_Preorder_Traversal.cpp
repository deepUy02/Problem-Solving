TC:-O(N)

class Solution {
public:
    TreeNode* solve(vector<int>&preorder,int mini ,int maxi ,int &index){
        if(index >= preorder.size()){
            return NULL;
        }
        if(preorder[index]<mini || preorder[index]>maxi){
            return NULL;
        }
        TreeNode* temp=new TreeNode(preorder[index++]);
        temp->left=solve(preorder,mini,temp->val,index);
        temp->right=solve(preorder,temp->val,maxi,index);
        return temp;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int preorderIndex=0;
        return solve(preorder,INT_MIN,INT_MAX,preorderIndex);
    }
};