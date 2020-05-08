class Solution {
public:
    string customSortString(string S, string T) {
        string ans = "";
        unordered_map<char, int> freq;
        for(auto i : T) {
            freq[i]++;
        }
        for(auto i : S) {
            while(freq[i]--) {
                ans += i;
            }
        }
        for(auto i = freq.begin(); i != freq.end(); i++) {
            while(i -> second > 0) {
                ans += (i -> first);
                i -> second--;
            }
        }
        return ans;
    }
};
