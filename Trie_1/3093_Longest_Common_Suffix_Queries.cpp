struct Node {
	Node *links[26];
	bool flag = false;
    	int index=-1;
	bool containKey(char ch) {
		return (links[ch - 'a'] != NULL);
	}

	void put(char ch, Node *node) {
		links[ch - 'a'] = node;
        
	}

	Node *get(char ch) {
		return links[ch - 'a'];
	}

	void setEnd() {
		flag = true;
	}
	
	bool isterminal() {
		return flag;
	}
};
class Trie {
private:
	Node* root;
    
public:
	Trie() {
		root = new Node();
	}
	void insert(string word,vector<string>& wc,int j) {
		Node *node = root;
		for (int i = 0; i < word.size(); i++) {
			if (!node->containKey(word[i])) {
				node->put(word[i], new Node());
			}
			//moves to reference trie
			node = node->get(word[i]);
            if(node->inexd!=-1){
                if(wc[node->ind].size()>word.size()) {
			node->index=j;
		}
            }
            else node->index=j;
            
		}
		node->setEnd();
	}

	int search(string word) {
		Node *node = root;
        	int p=-1;
		for (int i = 0; i < word.size(); i++) {
			if (!node->containKey(word[i])) {
                		return p;
			}
            
			node = node->get(word[i]);
            		p=node->index;
		}
		return p;
	}

	bool startsWith(string prefix) {
		Node* node = root;
		for (int i = 0; i < prefix.size(); i++) {
			if (!node->containKey(prefix[i])) {
				return false;
			}
			node = node->get(prefix[i]);
		}
		return true;
	}
};
class Solution {
public:
    vector<int> stringIndices(vector<string>& wc, vector<string>& wq) {
        int s=-1;
        int l=1e9;
        for(int i=0;i<wc.size();i++){
            if(l>wc[i].size()) {
		l=wc[i].size();s=i;
	    }
            reverse(wc[i].begin(),wc[i].end());
        }
        for(int i=0;i<wq.size();i++){
            reverse(wq[i].begin(),wq[i].end());
        }
        Trie trie;
        for(int i=0;i<wc.size();i++){
            trie.insert(wc[i],wc,i);

        }
        vector<int>ans;
        for(int i=0;i<wq.size();i++){
            int p=trie.search(wq[i]);
            if(p==-1) ans.push_back(s);
            else ans.push_back(p);
        }
        return ans;
    }
};