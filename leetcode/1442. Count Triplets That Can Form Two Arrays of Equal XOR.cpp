class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        vector<int> XOR(n + 1, 0);
        for(int i = 1; i <= n; i++) {
            XOR[i] = XOR[i - 1] ^ arr[i - 1];
        }
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = i + 1; j <= n; j++) {
                    // from i - j - 1
                    if(XOR[i - 1] == XOR[j]) {
                        ans += (j - i);
                    } 
            }
        }
        return ans;
    }
};
