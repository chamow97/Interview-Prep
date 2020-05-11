class WordDictionary {
public:
    struct node {
        node* next[26];
        bool isAWord;
        node() {
            isAWord = false;
            for(int i = 0; i < 26; i++) {
                next[i] = NULL;
            }
        }
    };
    /** Initialize your data structure here. */
    node *root;
    WordDictionary() {
        root = new node();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        node *curr = root;
        for(int i = 0; i < word.length(); i++) {
            if(curr -> next[word[i] - 'a'] == NULL) {
                curr -> next[word[i] - 'a'] = new node();
            }
            curr = curr -> next[word[i] - 'a'];
        }
        curr -> isAWord = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return canBeSearched(0, word, root);
    }
    
    bool canBeSearched(int index, string word, node *curr) {
        if(index >= word.length()) {
            return curr -> isAWord;
        } else {
            if(word[index] == '.') {
                bool isPossible = false;
                for(int i = 0; i < 26; i++) {
                    if(curr -> next[i] != NULL) {
                        isPossible = isPossible || canBeSearched(index + 1, word, curr -> next[i]);
                    }
                }
                return isPossible;
            } else {
                if(curr -> next[word[index] - 'a'] != NULL) {
                    return canBeSearched(index + 1, word, curr -> next[word[index] - 'a']);
                } else {
                    return false;
                }
            }
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
