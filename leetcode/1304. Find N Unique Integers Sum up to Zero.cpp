class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans;
        for(int i = 0; i < 2 * (n / 2); i += 2) {
            ans.push_back((-1) * (i + 1));
            ans.push_back((1) * (i + 1));
        }
        if(n % 2) {
            ans.push_back(0);
        }
        return ans;
    }
};
