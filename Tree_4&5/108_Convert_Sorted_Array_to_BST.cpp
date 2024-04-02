class Solution {
public:
    TreeNode* convertinBST(vector<int>nums,int left,int right){
        //base case
        if(right<=left)  return NULL;

        int mid=left+(right-left)/2;//calculate

        TreeNode* node=new TreeNode(nums[mid]);
        node->left=convertinBST(nums,left,mid);//call to left part 
        node->right=convertinBST(nums,mid+1,right);//call to right part

        return node;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return convertinBST(nums,0,nums.size());
    }
};