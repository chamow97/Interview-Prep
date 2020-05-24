class Solution {
public:
    bool isVowel(char a) {
        return (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u');
    } 
    int maxVowels(string s, int k) {
        int n = s.length();
        vector<int> prefix(n, 0);
        if(isVowel(s[0])) {
            prefix[0] = 1;
        }
        for(int i = 1; i < n; i++) {
            if(isVowel(s[i])) {
                prefix[i] = 1;
            }
            prefix[i] += prefix[i - 1];
        }
        int ans = 0;
        for(int i = k - 1; i < n; i++) {
            int pref = 0;
            if(i == k - 1) {
                pref = prefix[i];
            } else {
                pref = prefix[i] - prefix[i - k];
            }
            ans = max(ans, pref);
        }
        return ans;
    }
};
