class Solution {
public:
    vector<string> answer;
    void solve(string now, int l, int r, int n)
    {
        if(now.length() == 2*n)
        {
            answer.push_back(now);
            return;
        }
        if(l < n)
        {
            solve(now + "(", l+1, r, n);
        }
        if(r < l)
        {
            solve(now + ")", l, r + 1, n);
        }
    }
    vector<string> generateParenthesis(int n) {
        solve("", 0, 0, n);
        return answer;
    }
};