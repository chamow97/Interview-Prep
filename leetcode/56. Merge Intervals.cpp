class Solution {
public:
    static bool compFunc(vector<int> interval1, vector<int> interval2) {
        if(interval1[0] == interval2[0]) {
            return interval1[1] < interval2[1];
        }
        return interval1[0] < interval2[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), compFunc);
        if(intervals.size() == 0) {
            return intervals;
        }
        int start = intervals[0][0];
        int end = intervals[0][1];
        vector < vector<int> > ans;
        int i = 1;
        while(i < intervals.size()) {
            if(intervals[i][0] >= intervals[i - 1][0] && intervals[i][0] <= end) {
                end = max(max(intervals[i - 1][1], intervals[i][1]), end);
            } else {
                vector<int> currVal;
                currVal.push_back(start);
                currVal.push_back(end);
                ans.push_back(currVal);
                start = intervals[i][0];
                end = intervals[i][1];
            }
            i++;
        }
        vector<int> currVal;
        currVal.push_back(start);
        currVal.push_back(end);
        ans.push_back(currVal);
        return ans;
    }
};
