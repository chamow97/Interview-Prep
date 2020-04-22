class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.length();
        string ans(n, '#');
        stack<int> st;
        for(int i = 0; i < n; i++) {
            if(s[i] == '(') {
                st.push(i);
            } else if(s[i] == ')') {
                if(st.empty()) {
                    continue;
                }
                int prevVal = st.top();
                st.pop();
                ans[prevVal] = '(';
                ans[i] = ')';
            } else {
                ans[i] = s[i];
            }
        }
        string total = "";
        for(int i = 0; i < n; i++) {
            if(ans[i] != '#') {
                total += ans[i];
            }
        }
        return total;
    }
};
