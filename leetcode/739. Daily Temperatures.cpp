class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack< pair<int, int> > s;
        int n = T.size();
        vector<int> ans(n, 0);
        if(n == 0) {
            return ans;
        }
        s.push(make_pair(0, T[0]));
        for(int i = 1; i < n; i++) {
            while(!s.empty() && s.top().second < T[i]) {
                pair<int, int> curr = s.top();
                s.pop();
                ans[curr.first] = i - curr.first;
            }
            s.push(make_pair(i, T[i]));
        }
        return ans;
    }
};
