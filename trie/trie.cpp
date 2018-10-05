struct TrieNode {
    TrieNode* children[26];
    string word;
    TrieNode(): word("") {
        for (auto &c : children) {
            c = NULL;
        }
    };
};
class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *p = root;
        for (auto c : word) {
            int i = c - 'a';
            if (!p->children[i]) {
                p->children[i] = new TrieNode();
            }
            p = p->children[i];
        }
        p->word = word;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *p = root;
        for (auto c : word) {
            int i = c - 'a';
            if (!p->children[i]) {
                return false;
            }
            p = p->children[i];
        }
        return !p->word.empty();
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *p = root;
        for (auto c : prefix) {
            int i = c - 'a';
            if (!p->children[i]) {
                return false;
            }
            p = p->children[i];
        }
        return true;
    }
private:
    TrieNode *root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */