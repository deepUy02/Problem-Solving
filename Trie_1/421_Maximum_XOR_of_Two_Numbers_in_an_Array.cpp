class TrieNode{
public:
    TrieNode *child[2];
    
    TrieNode(){
        this->child[0] = NULL;  
        this->child[1] = NULL; 
    }
};
class Solution {
    TrieNode *newNode;
    
    void insert(int t){   //to insert each element into the Trie
        TrieNode *temp = newNode;
        bitset<32> bs(t);
        
        for(int j=31; j>=0; j--){
            if(!temp->child[bs[j]]) temp->child[bs[j]] = new TrieNode(); 
            temp = temp->child[bs[j]];
        }    
    }
    
public:
    int findMaximumXOR(vector<int>& nums) {
        newNode = new TrieNode();
        for(auto &i : nums) insert(i); 
        
        int ans=0; //Stores the maximum XOR possible so far
        for(auto i : nums){
            ans = max(ans, maxXOR(i));        }
        return ans;
    }
    
    int maxXOR(int x){
        TrieNode *temp = newNode;
        bitset<32> bs(x);
        int ans=0; 
        for(int j=31; j>=0; j--){
            if(temp->child[!bs[j]]) ans += (1<<j), temp = temp->child[!bs[j]]; 
           
            else temp = temp->child[bs[j]];
        }
        return ans;
    }
};