class Solution {
public:
    string patternize(string str) {
        unordered_map<char, string> m;
        int curr = 11;
        string pattern = "";
        for(auto i : str) {
            if(m.find(i) == m.end()) {
                m[i] = (to_string(curr));
                curr++;
            }
            pattern += (m[i] + "|");
        }
        return pattern;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        string output = patternize(pattern);
        vector<string> result;
        for(auto i : words) {
            if(patternize(i) == output) {
                result.push_back(i);
            }
        }
        return result;
    }
};
