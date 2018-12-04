class Solution {
public:
    bool isMatch(string s, string p) {
        int n1 = s.size();
        int n2 = p.size();
        vector< vector<int> > dp(n1 + 10,vector<int>(n2 + 10));
        for(int i = 0; i <= n1; i++)
        {
            for(int j = 0; j <= n2; j++)
            {
                dp[i][j] = -1;
            }
        }
        function<bool(int,int)> dfs = [&](int i, int j){
            if(j == n2)
                return (i == n1);
            
            if(dp[i][j] == -1)
            {
                bool match = false;
                if(i < n1 && (s[i] == p[j] || p[j] == '.'))
                {
                    match = true;
                }
                if(j < n2 - 1 && p[j + 1] == '*')
                {
                    dp[i][j] = (dfs(i, j + 2) || (match && dfs(i + 1, j)));
                }
                else
                {
                    dp[i][j] = (match && dfs(i + 1, j + 1));
                }
            }
            return dp[i][j] == 1;
        };
        return dfs(0, 0);
    }
};