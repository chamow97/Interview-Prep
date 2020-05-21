class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> m;
        for(auto i : s) {
            m[i]++;
        }
        int ans = 0, odd = 0;
        for(auto i : m) {
            if(i.second % 2) {
                odd++;
                ans += (i.second - 1);
            } else {
                ans += i.second;
            }
        }
        return odd > 0 ? ans + 1 : ans;
    }
};
