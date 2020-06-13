class Solution {
public:
    int minAddToMakeValid(string S) {
        int ans = 0;
        stack<char> s;
        for(auto i : S) {
            if(i == '(') {
                s.push('(');
            } else {
                if(s.empty()) {
                    ans++;
                } else {
                    s.pop();
                }
            }
        }
        while(!s.empty()) {
            ans++;
            s.pop();
        }
        return ans;
    }
};
