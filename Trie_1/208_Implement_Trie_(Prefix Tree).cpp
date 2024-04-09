class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    bool isterminal;
    TrieNode(char ch){
        data = ch;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        isterminal=false;
    }
};
class Trie {
    TrieNode* root;
public:
    Trie() {
        root=new TrieNode('\0');
    }
    void insertUtil(TrieNode* root,string word){
        //base case
        if(word.length()==0){
            root->isterminal=true;
            return;
        }
        //Assumption , word in CAPS
        int index=word[0]-'a';
        TrieNode* child;

        //present
        if(root->children[index] != NULL) {
            child=root->children[index];
        }
        else{
            //absent
            child=new TrieNode(word[0]);
            root->children[index]=child;
        }
        //Recursion
        insertUtil(child,word.substr(1));
    }
    void insert(string word) {
        insertUtil(root,word);
    }
    
    bool searchUtil(TrieNode* root,string word){
        if(word.length()==0){
            return root->isterminal;
        }
        int index=word[0]-'a';
        TrieNode* child;

        //present
        if(root->children[index]!=NULL){
            child=root->children[index];
        }
        else{
            //absent
            return false;
        }
        //Recursion
        return searchUtil(child,word.substr(1));
    }
    bool search(string word) {
        return searchUtil(root,word);
    }
    bool PrefixUtil(TrieNode* root,string word){
        if(word.length()==0){
            return true;
        }
        int index=word[0]-'a';
        TrieNode* child;

        //present
        if(root->children[index]!=NULL){
            child=root->children[index];
        }
        else{
            //absent
            return false;
        }
        //Recursion
        return PrefixUtil(child,word.substr(1));
    }
    bool startsWith(string prefix) {
        return PrefixUtil(root,prefix);
    }
};
