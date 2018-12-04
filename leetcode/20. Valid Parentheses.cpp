class Solution {
public:
    bool isValid(string s) {
        stack<char> p;
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{')
            {
                p.push(s[i]);
            }
            else
            {
                if(p.size() == 0)
                {
                    return false;
                }
                char cur = p.top();
                p.pop();
                if((s[i] == ')' && cur == '(') || (s[i] == '}' && cur == '{') || (s[i] == ']' && cur == '['))
                {
                    
                }
                else
                {
                    return false;
                }
            }
        }
        if(p.size() == 0)
        {
            return true;
        }
        return false;
    }
};