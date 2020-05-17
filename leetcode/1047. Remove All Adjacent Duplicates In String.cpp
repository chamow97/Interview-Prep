class Solution {
public:
    string removeDuplicates(string S) {
        stack<char> s;
        for(auto i : S) {
            if(s.empty() || s.top() != i) {
                s.push(i);
            } else {
                s.pop();
            }
        }
        string ans = "";
        while(!s.empty()) {
            ans += (s.top());
            s.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
