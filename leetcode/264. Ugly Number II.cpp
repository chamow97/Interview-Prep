class Solution {
public:
    int nthUglyNumber(int n) {
        int i = 0, j = 0, k = 0;
        vector<int> ans(1, 1);
        while(ans.size() < n) {
            int bestVal = min(ans[i] * 2, min(ans[j] * 3, ans[k] * 5));
            ans.push_back(bestVal);
            if(ans.back() == ans[i] * 2) {
                i++;
            }
            if(ans.back() == ans[j] * 3) {
                j++;
            }
            if(ans.back() == ans[k] * 5) {
                k++;
            }
        }
        return ans.back();
    }
};
