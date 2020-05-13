class Solution {
public:
    vector<int> diStringMatch(string S) {
        vector<int> ans;
        int i = 0, j = S.length();
        for(int k = 0; k < S.length(); k++) {
            if(S[k] == 'I') {
                ans.push_back(i++);
            } else {
                ans.push_back(j--);
            }
        }
        ans.push_back(i);
        return ans;
    }
};
