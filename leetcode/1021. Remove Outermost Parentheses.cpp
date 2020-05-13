class Solution {
public:
    string removeOuterParentheses(string S) {
        string ans = "";
        int opened = 0;
        for(auto i : S) {
            if(i == '(') {
                if(opened > 0) {
                    ans += i;
                }
                opened++;
            } else {
                if(opened > 1) {
                    ans += i;
                } 
                opened--;
            }
        }
        return ans;
    }
};
