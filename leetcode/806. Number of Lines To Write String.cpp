class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
        int line = 1, curr = 0, now = 0;
        for(int i = 0; i < S.length(); i++)
        {
            now = curr + widths[S[i] - 'a'];
            if(now > 100)
            {
                line += (now / 100);
                now = now % curr;
                curr = now;
            }
            else
            {
                curr = now;
            }
        }
        vector<int> answer;
        answer.push_back(line);
        answer.push_back(curr);
        return answer;
    }
};