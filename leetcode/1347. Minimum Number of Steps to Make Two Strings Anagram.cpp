class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);
        for(auto i : s) {
            freq1[i - 'a']++;
        }
        for(auto i : t) {
            freq2[i - 'a']++;
        }
        int ans = 0;
        for(int i = 0; i < 26; i++) {
            freq1[i] -= min(freq1[i], freq2[i]);
            ans += freq1[i];
        }
        return ans;
    }
};
