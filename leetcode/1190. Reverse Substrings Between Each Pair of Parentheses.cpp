class Solution {
public:
    string reverseParentheses(string str) {
        stack<int> s;
        for(int i = 0; i < str.length(); i++) {
            if(str[i] == '(') {
                s.push(i);
            } else if(str[i] == ')') {
                int lastLeftBrace = s.top();
                s.pop();
                reverse(str.begin() + lastLeftBrace + 1, str.begin() + i);
            }
        }
        string ans = "";
        for(auto i : str) {
            if(i != '(' && i != ')') {
                ans += i;
            }
        }
        return ans;
    }
};
