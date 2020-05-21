class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector< vector<int> > ans;
        for(int i = 1; i <= numRows; i++) {
            vector<int> num;
            if(i <= 2) {
                for(int j = 0; j < i; j++) {
                    num.push_back(1);
                }
                ans.push_back(num);
            } else {
                num.push_back(1);
                for(int j = 1; j <= i - 2; j++) {
                    num.push_back(ans[i - 2][j - 1] + ans[i - 2][j]);
                }
                num.push_back(1);
                ans.push_back(num);
            }
        }
        return ans;
    }
};
