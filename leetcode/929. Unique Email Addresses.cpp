class Solution {
public:
    string clean(string s) {
        int index = s.find('@');
        string before = "";
        for(int i = 0; i < index; i++) {
            if(s[i] == '+') {
                break;
            } else if(s[i] != '.') {
                before += s[i];
            }
        }
        string after = "";
        for(int i = index; i < s.length(); i++) {
            after += s[i];
        }
        return before + after;
    }
    int numUniqueEmails(vector<string>& emails) {
        set<string> s;
        for(string i : emails) {
            s.insert(clean(i));
        }
        return s.size();
    }
};
