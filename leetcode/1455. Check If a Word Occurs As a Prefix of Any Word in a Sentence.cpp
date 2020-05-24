class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        stringstream s(sentence); // Used for breaking words 
        string word; // to store individual words 
        int count = 0; 
        while (s >> word) {
            count++;     
            int j = 0, i = 0;
            while(i < word.length() && j < searchWord.length() && word[i] == searchWord[j]) {
                i++;
                j++;
            }
            if(j == searchWord.length()) {
                return count;
            }
        }
        return -1; 
    }
};
