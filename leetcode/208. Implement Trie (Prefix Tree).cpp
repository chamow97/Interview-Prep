class Trie {
public:
    /** Initialize your data structure here. */
    struct node {
        bool isWhole;
        node *next[26];
        node() {
            isWhole = false;
            for(int i = 0; i < 26; i++) {
                next[i] = NULL;
            }
        }
    };
    node *root;
    Trie() {
        root = new node();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        node *current = root;
        for(int i = 0; i < word.length(); i++) {
            if(current -> next[word[i] - 'a'] == NULL) {
                current -> next[word[i] - 'a'] = new node();
            }
            current = current -> next[word[i] - 'a'];
        }
        current -> isWhole = true;
    }
    
    node* isWordAvailable(string word) {
        node *current = root;
        for(int i = 0; i < word.length(); i++) {
            if(current -> next[word[i] - 'a'] == NULL) {
                return NULL;
            }
            current = current -> next[word[i] - 'a'];
        }
        return current;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        node *current = isWordAvailable(word);
        return current != NULL && current -> isWhole;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        node *current = isWordAvailable(prefix);
        return current != NULL;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
