TC:-O(H)
SP:-O(1)

int findCeil(BinaryTreeNode<int> *root, int key){
    int ceil = -1;
    while(root != NULL){
        if(root->data==key){
            return root->data;
        }
        else if(root->data < key) {
            root = root->right;
        } else {
            ceil = root->data;
            root = root->left;
        }
    }
    return ceil;
}