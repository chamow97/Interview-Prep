class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.length();
        int maxPossible = n - k + 1;
        int totalNeeded = pow(2, k);
        set<string> st;
        if(maxPossible < totalNeeded) {
            return false;
        } else {
            string str = "";
            for(int i = 0; i < k; i++) {
                str += s[i];
            }
            int i = k;
            while(i < n) {
                st.insert(str);
                str.erase(str.begin());
                str += s[i++];
            }
            st.insert(str);
            return st.size() >= totalNeeded;
        }
    }
};
