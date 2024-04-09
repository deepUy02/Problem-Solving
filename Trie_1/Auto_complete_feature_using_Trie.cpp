TC:-O(N*L)
SC:-O(N*L+N * ALPHABET_SIZE)

#include<bits/stdc++.h>
using namespace std;
#define ALPHABET_SIZE (26)
// Converts key current character into index && using lower case
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')
struct TrieNode {
	struct TrieNode* children[ALPHABET_SIZE];

	// isWordEnd is true if the node represents
	// end of a word
	bool isTerminal;
};
struct TrieNode* getNode(void)
{
	struct TrieNode* newNode = new TrieNode;
	newNode->isTerminal = false;

	for (int i = 0; i < ALPHABET_SIZE; i++)
		newNode->children[i] = NULL;

	return newNode;
}
//Insertion
void insert(struct TrieNode* root, const string key)
{
	struct TrieNode* pCrawl = root;
	for (int level = 0; level < key.length(); level++) {
		int index = CHAR_TO_INDEX(key[level]);
		if (!pCrawl->children[index])
			pCrawl->children[index] = getNode();

		pCrawl = pCrawl->children[index];
	}
	// mark last node as leaf
	pCrawl->isTerminal = true;
}

bool isLastNode(struct TrieNode* root)
{
	for (int i = 0; i < ALPHABET_SIZE; i++)
		if (root->children[i])
			return 0;
	return 1;
}
//Print suggestions
void suggestionsRec(struct TrieNode* root,string currPrefix)
{
	// found a string in Trie with the given prefix
	if (root->isTerminal)
		cout << currPrefix << endl;

	for (int i = 0; i < ALPHABET_SIZE; i++)
		if (root->children[i]) {
			// child node character value
			char child = 'a' + i;
			suggestionsRec(root->children[i],currPrefix + child);
		}
}
// print suggestions for given query prefix.
int printAutoSuggestions(TrieNode* root, const string query)
{
	struct TrieNode* pCrawl = root;
	for (char c : query) {
		int ind = CHAR_TO_INDEX(c);
		// no string in the Trie has this prefix
		if (!pCrawl->children[ind])
			return 0;
		pCrawl = pCrawl->children[ind];
	}
	// If prefix is present as a word, but
	// there is no subtree below the last
	// matching node.
	if (isLastNode(pCrawl)) {
		cout << query << endl;
		return -1;
	}
	suggestionsRec(pCrawl, query);
	return 1;
}
int main()
{
	struct TrieNode* root = getNode();
	insert(root, "hello");
	insert(root, "dog");
	insert(root, "hell");
	insert(root, "cat");
	insert(root, "a");
	insert(root, "hel");
	insert(root, "help");
	insert(root, "helps");
	insert(root, "helping");
	cout<<"Suggestions for hel :-"<<endl;
	int comp = printAutoSuggestions(root, "hel");
	if (comp == -1)
		cout << "No other strings found with this prefix\n";

	else if (comp == 0)
		cout << "No string found with this prefix\n";

	cout<<"Suggestions for ca :-"<<endl;
	int ans  = printAutoSuggestions(root, "ca");
	if (ans == -1)
		cout << "No other strings found with this prefix\n";

	else if (ans == 0)
		cout << "No string found with this prefix\n";


	return 0;
}
