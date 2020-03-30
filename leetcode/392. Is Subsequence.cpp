class Solution {
public:
    bool isSubsequence(string s, string t) {
        int ptr1 = 0, ptr2 = 0;
        int n = s.length();
        int m = t.length();
        while(ptr1 < n && ptr2 < m) {
            if(s[ptr1] == t[ptr2]) {
                ptr1++;
                ptr2++;
            } else {
                ptr2++;
            }
        }
        return ptr1 >= n;
    }
};
