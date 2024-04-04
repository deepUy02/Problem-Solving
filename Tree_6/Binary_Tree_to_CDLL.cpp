Node *bTreeToCList(Node *root)
    {
        if(root == NULL) 
            return NULL;
        
        Node* prev = NULL;
        stack<Node*>s;
        Node* curr = root;
        
        Node* head = NULL;
        Node* tail = NULL;
        
        // inorder traversal
        while(curr || s.empty() == false) {
            while(curr) {
                s.push(curr);
                curr = curr->left;
            }
            
            curr = s.top();
            s.pop();
            
            if(!head)
                head = curr;
            tail = curr;
            
            if(prev)
                prev->right = curr;
            curr->left = prev;
            
            prev = curr;
            curr = curr->right;
        }
        
        head->left = tail;
        tail->right = head;
        
        return head;
    }