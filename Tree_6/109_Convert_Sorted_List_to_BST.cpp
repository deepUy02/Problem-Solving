class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == NULL)    return NULL;

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;

        while( fast != NULL && fast->next != NULL){
            prev = slow;
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        TreeNode* root = new TreeNode(slow->val);
        if(slow == head)    return root;

        prev -> next = NULL;
        root -> left = sortedListToBST(head);
        root -> right = sortedListToBST(slow->next);
        return root;
    }
};