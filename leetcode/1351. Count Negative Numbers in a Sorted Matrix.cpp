class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int i = 0;
        int j = m - 1;
        int ans = 0;
        while(i < n && j >= 0) {
            int currCount = 0;
            while(j >= 0 && grid[i][j] < 0) {
                j--;
                currCount++;
            }
            ans += (currCount * (n - i));
            i++;
        }
        return ans;
    }
};
