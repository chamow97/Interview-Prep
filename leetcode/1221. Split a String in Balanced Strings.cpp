class Solution {
public:
    int balancedStringSplit(string s) {
        int ans = 0;
        int val = 0;
        if(s[0] == 'L') {
            val = -1;
        } else {
            val = 1;
        }
        for(int i = 1; i < s.length(); i++) {
            if(s[i] == 'L') {
                val += (-1);
            } else {
                val += (1);
            }
            if(val == 0) {
                ans++;
            }
        }
        return ans;
    }
};
