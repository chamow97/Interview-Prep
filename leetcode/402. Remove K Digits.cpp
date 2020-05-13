class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> s;
        if(k >= num.length()) {
            return "0";
        }
        s.push(num[0]);
        for(int i = 1; i < num.length(); i++) {
            while(!s.empty() && k > 0 && num[i] < s.top()) {
                s.pop();
                k--;
            }
            s.push(num[i]);
        }
        while(!s.empty() && k > 0) {
            s.pop();
            k--;
        }
        string ans = "";
        while(!s.empty()) {
            ans = (s.top()) + ans;
            s.pop();
        }
        int i = 0;
        while(i < ans.length() && ans[i] == '0') {
            i++;
        }
        string newAns(ans.begin() + i, ans.end());
        if(newAns.length() == 0) {
            return "0";
        }
        return newAns;
    }
};
