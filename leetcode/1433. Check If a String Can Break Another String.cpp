class Solution {
public:
    bool isPossible(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();
        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);
        for(auto i : s1) {
            freq1[i - 'a']++;
        }
        for(auto i : s2) {
            freq2[i - 'a']++;
        }
        bool possible = true;
        int i = 0;
        while(i < 26) {
            int j = i;
            while(j < 26 && freq1[i] > 0) {
                int currPossible = min(freq1[i], freq2[j]);
                freq2[j] -= currPossible;
                freq1[i] -= currPossible;
                j++;
            }
            if(freq1[i] > 0) {
                return false;
            }
            i++;
        }
        return true;
    }
    bool checkIfCanBreak(string s1, string s2) {
        return isPossible(s1, s2) || isPossible(s2, s1);
    }
};
