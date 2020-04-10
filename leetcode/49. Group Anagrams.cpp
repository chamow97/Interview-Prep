class Solution {
public:
    string encode(string str) {
        vector<int> asc;
        for(int i = 0; i < str.length(); i++) {
            asc.push_back((int)(str[i] - 'a'));
        }
        string ans = "";
        sort(asc.begin(), asc.end());
        for(int i = 0; i < asc.size(); i++) {
            ans += to_string(asc[i]);
            ans += "|";
        }
        return ans;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        unordered_map< string, vector<int> > m;
        for(int i = 0; i < n; i++) {
            string encodedString = encode(strs[i]);
            m[encodedString].push_back(i);
        }
        vector< vector<string> > ans;
        for(auto li : m) {
            vector<string> curr;
            for(int i = 0; i < li.second.size(); i++) {
                curr.push_back(strs[li.second[i]]);
            }
            ans.push_back(curr);
        }
        return ans;
    }
};
