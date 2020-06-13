class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        set< pair<double, int> > s;
        for(int i = 0; i < points.size(); i++) {
            double currDist = sqrt(pow(points[i][0], 2) + pow(points[i][1], 2));
            s.insert({currDist, i});
            if(s.size() > K) {
                auto it = s.end();
                it--;
                s.erase(it);
            }
        }
        vector< vector<int> > ans;
        for(auto i : s) {
            ans.push_back(points[i.second]);
        }
        return ans;
    }
};
