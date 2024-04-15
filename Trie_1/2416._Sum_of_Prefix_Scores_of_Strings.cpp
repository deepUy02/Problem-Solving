class Solution {
public:
    class TrieNode{
        public:TrieNode* node[26];
        int count = 0;

        TrieNode(){
            for(int i = 0;i< 26;i++){
                node[i] = NULL;
                count = 0;
            }
        }
    };

    void add(TrieNode* root , string s){
        for(int i = 0;i < s.length();i++){
            int index = s[i] - 'a';
            if(root->node[index] == NULL){
                root->node[index] = new TrieNode();
            }
            root = root->node[index];
            root->count++;
        }
    }
    int find(string s ,TrieNode* root){
        int ans = 0;
        for(int i = 0;i< s.length();i++){
            int index = s[i] - 'a';
            root = root->node[index];
            ans+=root->count;
        }
        return ans;
    }
    vector<int> sumPrefixScores(vector<string>& words) {
        TrieNode* root = new TrieNode();

        for(string word:words){
            add(root,word);
        }
        vector<int>ans;
        for(string word : words){
            ans.push_back(find(word,root));
        }
        return ans;
    }
};