class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans;
        int n = temperatures.size();
        vector<int> *adj = new vector<int>[101];
        for(int i = 0; i < n; i++)
        {
            adj[temperatures[i]].push_back(i);
        }
        for(int i = 0; i < n; i++)
        {
            int answer = 1000000;
            for(int j = temperatures[i] + 1; j <= 100; j++)
            {
                auto pos = upper_bound(adj[j].begin(), adj[j].end(), i);
                if(pos == adj[j].end())
                {
                    continue;
                }
                
                answer = min(*pos - i, answer);
                
               
            }            
            if(answer == 1000000)
            {
                answer = 0;
            }
            ans.push_back(answer);
        }
        return ans;
       
    }
};