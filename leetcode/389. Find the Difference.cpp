class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> freq(26, 0);
        for(auto i : s) {
            freq[i - 'a']++;
        }
        for(auto i : t) {
            freq[i - 'a']--;
        }
        int ans = -1;
        for(int i = 0; i < 26; i++) {
            if(freq[i] < 0) {
                return (char)(i + 'a');
            }
        }
        return 'a';
    }
};
