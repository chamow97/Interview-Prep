class Solution {
public:
    int scoreOfParentheses(string S) {
        int left = 0;
        int ans = 0;
        for(int i = 0; i < S.length(); i++) {
            if(S[i] == '(') {
                left++;
            } else {
                left--;
            }
            if(S[i] == ')' && S[i - 1] == '(') {
                // we are directly doing this because sometime later
                // this is going to multiplied by number of ( before this
                // so why not add it now itself
                ans += (pow(2, left));
            }
        }
        return ans;
    }
};
