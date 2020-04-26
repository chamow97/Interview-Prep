class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        // stack stores the place at which the string is corrupted 
        // and is used to calculate the substring, get the max of those
        // which will indirectly give the max length of correct string
        
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '(') {
                st.push(i);
            } else {
                if(!st.empty() && s[st.top()] == '(') {
                    st.pop();
                } else {
                    st.push(i);
                }
            }
        }
        
        if(st.empty()) {
            return s.length();
        }
        
        int maxLen = 0;
        int currIndex = s.length();
        while(!st.empty()) {
            maxLen = max(maxLen, currIndex - st.top() - 1);
            currIndex = st.top();
            st.pop();
        }
        maxLen = max(maxLen, currIndex);
        return maxLen;
    }
};
