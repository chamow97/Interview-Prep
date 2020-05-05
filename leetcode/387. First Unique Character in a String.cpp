class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> freq(26, 0);
        for(int i = 0; i < s.length(); i++) {
            if(freq[s[i] - 'a'] == 0) {
                freq[s[i] -  'a'] = i + 1;
            } else if(freq[s[i] - 'a'] > 0) {
                freq[s[i] - 'a'] *= (-1);
            }
        }
        int minIndex = INT_MAX;
        for(int i = 0; i < 26; i++) {
            if(freq[i] > 0) {
                minIndex = min(minIndex, freq[i] - 1);
            }
        }
        return minIndex == INT_MAX ? -1 : minIndex;
    }
};
