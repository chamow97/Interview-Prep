
class Solution {

    public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = difficulty.size();
        
       vector<int> m(100011, 0);
        vector<int> maxLen(100011, 0);
        for(int i = 0; i < n; i++)
        {
            m[difficulty[i]] = max(m[difficulty[i]], profit[i]);
        }
        for(int i = 1; i < 100001; i++)
        {
            maxLen[i] = max(maxLen[i-1], m[i]);
        }
        int total = 0;
        n = worker.size();
        for(int i = 0; i < n; i++)
        {
            //cout << worker[i] << ' ' << maxLen[worker[i]] << '\n';
            total += maxLen[worker[i]];
        }
        return total;
    }
};