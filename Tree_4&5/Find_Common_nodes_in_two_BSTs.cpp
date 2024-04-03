void traverse(Node *root,map<int,int>&mp)
    {
        if(!root) return;
        traverse(root->left,mp);
        mp[root->data]++;
        traverse(root->right,mp);
        
    }
    vector <int> findCommon(Node *root1, Node *root2)
    {
     //Your code here
     if(!root1||!root2) return {-1};
     vector<int>ans;
     map<int,int>mp;
     traverse(root1,mp);
     traverse(root2,mp);
     for(auto it: mp)
     {
         if(it.second==2) ans.push_back(it.first);
     }
     return ans;
     
    }