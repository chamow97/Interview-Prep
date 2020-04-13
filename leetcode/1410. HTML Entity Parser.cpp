class Solution {
public:
    string getString(string str) {
        if(str == "&quot;") {
            return "\"";
        } else if(str == "&apos;") {
            return "'";
        } else if(str == "&amp;") {
            return "&";
        } else if(str == "&gt;") {
            return ">"; 
        } else if(str == "&lt;") {
            return "<";
        } else if(str == "&frasl;") {
            return "/";
        } else {
            return str;
        }
    }
    string entityParser(string str) {
        string ans = "";
        int i = 0;
        int n = str.length();
        while(i < n) {
            while(i < n && str[i] != '&') {
                ans += (str[i]);
                i++;
            }
            string curr = "";
            while(i < n && str[i] != ';' && str[i] != ' ') {
                curr += str[i];
                i++;
            }
            if(i < n) {
                curr += str[i];
            }
            ans += getString(curr);
            i++;
        }
        return ans;
    }
};
