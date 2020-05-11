class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        vector<int> ans;
        ans.push_back(label);
        while(label > 1) {
            int upper = log2(label) + 1;
            int lower = upper - 1;
            upper = pow(2, upper) - 1;
            lower = pow(2, lower);
            label = (upper - label + lower) / 2;
            ans.push_back(label);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
