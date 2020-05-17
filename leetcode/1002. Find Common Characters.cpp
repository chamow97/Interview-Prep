class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<int> common(26, INT_MAX);
        for(auto i : A) {
            vector<int> freq(26, 0);
            for(auto j : i) {
                freq[j - 'a']++;
            }
            for(int i = 0; i < 26; i++) {
                common[i] = min(common[i], freq[i]);
            }
        }
        vector<string> ans;
        for(int i = 0; i < 26; i++) {
            for(int j = 0; j < common[i]; j++) {
                string now(1, (i + 'a'));
                ans.push_back(now);
            }
        }
        return ans;
    }
};
