class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    unordered_map<string, int> freq;
};

class AutoCompleteSystem {
private:
    TrieNode* root;
    TrieNode* curr;
    string currQuery;

    static bool compare(pair<string, int>& a, pair<string, int>& b) {
        return a.second > b.second || (a.second == b.second && a.first < b.first);
    }

public:
    AutoCompleteSystem(vector<string>& sentences, vector<int>& times) {
        root = new TrieNode();
        curr = root;
        currQuery = "";

        for (int i = 0; i < sentences.size(); ++i) {
            insert(sentences[i], times[i]);
        }
    }

    void insert(string sentence, int time) {
        TrieNode* node = root;
        for (char c : sentence) {
            if (!node->children[c]) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
            node->freq[sentence] += time;
        }
    }

    vector<string> input(char c) {
        if (c == '#') {
            insert(currentQuery, 1);
            currQuery = "";
            curr = root;
            return {};
        }

        currentQuery += c;
        if (!curr->children[c]) {
            curr->children[c] = new TrieNode();
            curr = curr->children[c];
            return {};
        }

        curr = curr->children[c];
        vector<pair<string, int>> suggestions(curr->freq.begin(), curr->freq.end());
        sort(suggestions.begin(), suggestions.end(), compare);

        vector<string> result;
        for (int i = 0; i < min(3, (int)suggestions.size()); ++i) {
            result.push_back(suggestions[i].first);
        }

        return result;
    }
};