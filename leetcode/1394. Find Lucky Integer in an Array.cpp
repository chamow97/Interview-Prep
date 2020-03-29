class Solution {
public:
    int findLucky(vector<int>& arr) {
        vector<int> freq(501, 0);
        int n = arr.size();
        for(int i = 0; i < n; i++) {
            freq[arr[i]]++;
        }
        int ans = -1;
        for(int i = 1; i <= 500; i++) {
            if(freq[i] == i) {
                ans = i;
            }
        }
        return ans;
    }
};
