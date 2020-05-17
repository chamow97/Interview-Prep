class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        unordered_map<string, int> m;
        istringstream ss(A); 
  
        do { 
            // Read a word 
            string word; 
            ss >> word; 

            m[word]++;

            // While there is more to read 
        } while (ss); 
        
        istringstream s1(B);
        do { 
            // Read a word 
            string word; 
            s1 >> word; 

            m[word]++;

            // While there is more to read 
        } while (s1); 
        vector<string> ans;
        for(auto i : m) {
            if(i.second == 1) {
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};
