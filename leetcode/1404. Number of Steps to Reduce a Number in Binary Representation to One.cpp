class Solution {
public:
    int numSteps(string s) {
        int n = s.length();
        int j = n - 1;
        int ans = 0;
        while(j >= 0) {
            if(s[j] == '0') {
                j--;
                ans++;
            } else {
                if(j <= 0) {
                    break;
                }
                ans++;
                while(j >= 0 && s[j] == '1') {
                    j--;
                    ans++;
                }
                if(j < 0) {
                    break;
                } else {
                    s[j] = '1';
                }
            }
        }
        return ans;
    }
};
