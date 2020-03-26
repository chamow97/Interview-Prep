class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> reqFreq(26, 0);
        vector<int> total;
        int n = s.length();
        int m = p.length();
        for(int i = 0; i < m; i++) {
            reqFreq[p[i] - 'a']++;
        }
        vector< vector<int> > freq(n + 1, vector<int>(26, 0));
        for(int i = 0; i < n; i++) {
            freq[i + 1][s[i] - 'a']++;
        }
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j < 26; j++) {
                freq[i][j] += freq[i - 1][j];
            }
        }
        int ptr1 = 1, ptr2 = m;
        int ans = 0;
        while(ptr2 <= n) {
            bool isPossible = true;
            for(int i = 0; i < 26; i++) {
                int diff = freq[ptr2][i] - freq[ptr1 - 1][i];
                int req = reqFreq[i];
                if(diff != req) {
                    isPossible = false;
                    break;
                }
            }
            if(isPossible) {
                total.push_back(ptr1 - 1);
            }
            ptr1++;
            ptr2++;
        }
        return total;
    }
};
