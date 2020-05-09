class Solution {
public:
    int characterReplacement(string s, int k) {
        if(s.length() <= 1) {
            return s.length();
        }
        s = " " + s;
        int n = s.length();
        vector< int > freq(26, 0);
        int i = 1, j = 2, ans = 1;
        freq[s[i] - 'A']++;
        freq[s[j] - 'A']++;
        while(j < n) {
            int maxRepeating = 0;
            for(int m = 0; m < 26; m++) {
                maxRepeating = max(maxRepeating, freq[m]);
            }
            if(maxRepeating + k >= (j - i + 1)) {
                ans = max(ans, j - i + 1);
                j++;
                if(j < n)
                    freq[s[j] - 'A']++;
            } else {
                freq[s[i] - 'A']--;
                i++;
                if(i == j) {
                    j = i + 1;
                    if(j < n) {
                        freq[s[j] - 'A']++;
                    }
                }
            }
        }
        return ans;
    }
};
