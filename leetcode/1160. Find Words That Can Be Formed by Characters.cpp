class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> freq(26, 0);
        for(auto i : chars) {
            freq[i - 'a']++;
        }
        int ans = 0;
        for(auto i : words) {
            vector<int> curr(26, 0);
            for(auto j : i) {
                curr[j - 'a']++;
            }
            bool possible = true;
            for(int i = 0; i < 26; i++) {
                if(freq[i] < curr[i]) {
                    possible = false;
                    break;
                }
            }
            if(possible) {
                ans += (i.length());
            }
        }
        return ans;
    }
};
