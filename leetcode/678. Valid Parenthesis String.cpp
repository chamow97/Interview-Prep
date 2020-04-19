class Solution {
public:
    bool checkValidString(string str) {
        // 2 stacks
        stack<int> leftP, ast;
        for(int i = 0; i < str.length(); i++) {
            if(str[i] == '(') {
                leftP.push(i);
            } else if(str[i] == '*') {
                ast.push(i);
            } else {
                if(!leftP.empty()) {
                    leftP.pop();
                } else if(!ast.empty()) {
                    ast.pop();
                } else {
                    return false;
                }
            }
        }
        // balanced the ) parantheses
        while(!leftP.empty() && !ast.empty()) {
            if(leftP.top() > ast.top()) {
                return false;
            } else {
                leftP.pop();
                ast.pop();
            }
        }
        return leftP.empty();
    }
};
