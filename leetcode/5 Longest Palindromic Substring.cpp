class Solution {
public:
    string longestPalindrome(string s) {
        int maxLen = -1, start = 0;
        int n = s.length();
        for(int i = 0; i < n; i++)
        {
            int left = i, right = i;
            while(s[right + 1] == s[left])
            {
                i++;
                right++;
            }
            while(left - 1 >= 0 && right + 1 < n && s[right + 1] == s[left - 1])
            {
                right++;
                left--;
            }
            int currLen = right - left + 1;
            if(currLen > maxLen)
            {
                maxLen = currLen;
                start = left;
            }
        }
        string ans = s.substr(start, maxLen);
        return ans;
    }
};