class Solution {
public:
    vector<string> arr;
    vector<string> answer;
    int n;
    string digits1;
    void solve(string curr, int next)
    {
        if(next == n)
        {
            answer.push_back(curr);
            return;
        }
        for(int i = 0; i < arr[digits1[next] - '0'].length(); i++)
        {
            string current = curr + char(arr[digits1[next] - '0'][i]);
            solve(current, next + 1);
        }
    }
    vector<string> letterCombinations(string digits) {
        n = digits.length();
        digits1 = digits;
        if(n == 0)
        {
            return answer;
        }
        for(int i = 0; i < arr[digits[0] - '0'].length(); i++)
        {
            char current = arr[int(digits[0] - '0')][i];
            string curr = "";
            curr += current;
            solve(curr, 1);
        }
        return answer;
    }
    Solution()
    {
        arr.resize(10);
        arr[2] = "abc";
        arr[3] = "def";
        arr[4] = "ghi";
        arr[5] = "jkl";
        arr[6] = "mno";
        arr[7] = "pqrs";
        arr[8] = "tuv";
        arr[9] = "wxyz";
    }
};