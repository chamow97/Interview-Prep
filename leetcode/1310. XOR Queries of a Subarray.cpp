class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        for(int i = 1; i < n; i++) {
            arr[i] ^= arr[i - 1];
        }
        vector<int> ans;
        for(auto i : queries) {
            int l = i[0];
            int r = i[1];
            if(l == 0) {
                ans.push_back(arr[r]);
            } else {
                ans.push_back(arr[r] ^ arr[l - 1]);
            }
        }
        return ans;
    }
};
