class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();
        if(n > m) {
            return false;
        }
        vector<int> freq(26, 0);
        for(auto i : s1) {
            freq[i - 'a']++;
        }
        vector<int> freq1(26, 0);
        for(int i = 0; i < n - 1; i++) {
            freq1[s2[i] - 'a']++;
        }
        int i = n - 1;
        int j = 0;
        while(i < m) {
            freq1[s2[i] - 'a']++;
            bool possible = true;
            for(int j = 0; j < 26; j++) {
                if(freq[j] != freq1[j]) {
                    possible = false;
                    break;
                }
            }
            if(possible) {
                return true;
            }
            freq1[s2[j] - 'a']--;
            j++;
            i++;
        }
        return false;
    }
};
