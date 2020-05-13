class Solution {
public:
    string freqAlphabets(string s) {
        int i = 0;
        int n = s.length();
        string ans = "";
        while(i < n) {
            if(i + 2 < n) {
                if(s[i + 2] == '#') {
                    int currVal = ((s[i] - '0') * 10) + (s[i + 1] - '0');
                    ans += ('a' + currVal - 1);
                    i = i + 3;
                } else {
                    ans += ((s[i] - '0' - 1) + 'a');
                    i++;
                }
            } else {
                ans += ((s[i] - '0' - 1) + 'a');
                i++;
            }
        }
        return ans;
    }
};
