class Solution {
public:
    string hash(string str) {
        string h = "";
        unordered_map<char, int> m;
        int it = 0;
        for(auto i : str) {
            if(m.find(i) == m.end()) {
                m[i] = it++;
            }
            h += (to_string(m[i]) + "#");
        }
        return h;
    }
    bool isIsomorphic(string s, string t) {
        return hash(s) == hash(t);
    }
};
