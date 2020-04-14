class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int totalShift = 0;
        for(int i = 0; i < shift.size(); i++) {
            if(shift[i][0] == 0) {
                totalShift -= shift[i][1];
            } else {
                totalShift += shift[i][1];
            }
        }
        string ans = "";
        if(totalShift < 0) {
            totalShift = abs(totalShift);
            totalShift %= (s.length());
            for(int i = totalShift; i < s.length(); i++) {
                ans += s[i];
            }
            for(int i = 0; i < totalShift; i++) {
                ans += s[i];
            }
        } else {
            totalShift %= (s.length());
            for(int i = s.length() - totalShift; i < s.length(); i++) {
                ans += s[i];
            }
            for(int i = 0; i < s.length() - totalShift; i++) {
                ans += s[i];
            }
        }
        return ans;
    }
};
