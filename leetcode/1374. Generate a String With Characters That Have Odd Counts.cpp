class Solution {
public:
    string generateTheString(int n) {
        string ans = "";
        for(int i = 0; i < n - (n % 2 == 0); i++) {
            ans += 'a';
        }
        if(n % 2 == 0) {
            ans += 'b';
        }
        return ans;
    }
};
