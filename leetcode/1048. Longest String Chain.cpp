class Solution {
public:
    static bool myComp(string a, string b) {
        return a.length() < b.length();
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), myComp);
        map<string, int> dp;
        int maximum = 1;
        for(auto word : words) {
            for(int i = 0; i < word.length(); i++) {
                dp[word] = max(dp[word], 1 + dp[word.substr(0, i) + word.substr(i + 1)]);
                maximum = max(maximum, dp[word]);
            }
        }
        return maximum;
    }
};
