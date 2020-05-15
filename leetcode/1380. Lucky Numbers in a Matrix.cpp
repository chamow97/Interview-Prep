class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> rowMin;
        vector<int> colMax;
        for(int i = 0; i < matrix.size(); i++) {
            rowMin.push_back(*min_element(matrix[i].begin(), matrix[i].end()));
        }
        for(int i = 0; i < matrix[0].size(); i++) {
            int currMax = 0;
            for(int j = 0; j < matrix.size(); j++) {
                currMax = max(currMax, matrix[j][i]);
            }
            colMax.push_back(currMax);
        }
        vector<int> ans;
        for(int i = 0; i < rowMin.size(); i++) {
            for(int j = 0; j < colMax.size(); j++) {
                if(rowMin[i] == colMax[j]) {
                    ans.push_back(rowMin[i]);
                }
            }
        }
        return ans;
    }
};
