class Solution {
public:
    string reverseWords(string s) {
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == ' ' || i == 0) {
                int pos = s.length();
                for(int j = i + 1; j < s.length(); j++) {
                    if(s[j] == ' ') {
                        pos = j;
                        break;
                    }
                }
                reverse(s.begin() + (i == 0 ? i : i + 1), s.begin() + pos);
            }
        }
        return s;
    }
};
