class Solution {
public:
    static bool compFunc(vector<int> &a, vector<int> &b) {
        if(a[0] == b[0]) {
            return a[1] > b[1];
        }
        return a[0] < b[0];
    }
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), compFunc);
        int lastBestLeft = 0, lastBestRight = 0;
        int needed = 1;
        lastBestLeft = intervals[0][0];
        lastBestRight = intervals[0][1];
        for(int i = 1; i < intervals.size(); i++) {
            if(lastBestRight < intervals[i][1]) {
                lastBestRight = intervals[i][1];
                ++needed;
            }
        }
        return needed;
    }
};
