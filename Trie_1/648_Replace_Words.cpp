struct Node {
    Node *links[26];
    bool flag = false;
    
    bool containsKey(char ch){
	return links[ch-'a'] != NULL;
    }
    void put(char ch, Node *node){
	links[ch-'a'] = node;
    }
    Node *get(char ch){
	return links[ch-'a'];
    }
    void setEnd(){
	flag = true}

    bool isTerminal(){
	return flag;
    }
};

class Trie {
    Node* root;
public:
    Trie() {root = new Node();}  
    
    void insert(string word){
        Node *node = root;
        for(int i=0; i<word.length(); i++){
            if(!node->containsKey(word[i])){
		node->put(word[i], new Node());
	    }
            node = node->get(word[i]);
        }
        node->setEnd();
    }
    
    string givePrefix(string word){
        Node *node = root;
        for(int i=0; i<word.length(); i++){
            if(node->isTerminal()){
		return word.substr(0, i);     
	    }
            else if(!node->containsKey(word[i])){
		return word;
	    }
            node = node->get(word[i]);
        }
        return word;
    }
    
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie *trie = new Trie();
        for(auto it: dictionary){
            trie->insert(it);
        }
        
        sentence += ' ';
        vector<string>words;
        string s;
        for(int i=0; i<sentence.length(); i++){
            if(sentence[i]!=' '){s += sentence[i];}
            else{
                words.push_back(s);
                s = "";
            }
        }
        
        for(auto &it: words){
            it = trie->givePrefix(it);
        }

        s = "";
        s += words[0];
        for(int i=1; i<words.size(); i++){
		s += ' ' + words[i];
        }

        return s;
    }
};