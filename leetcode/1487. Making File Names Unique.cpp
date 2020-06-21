class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        vector<string> ans;
        map<string, int> m;
        for(auto i : names) {
            if(m.count(i)) {
                for(int j = m[i] + 1; ; j++) {
                    if(!m.count(i + "(" + to_string(j) + ")")) {
                        m[i]++;
                        m[i + "(" + to_string(j) + ")"] = 0;
                        i = i + "(" + to_string(j) + ")";
                        break;
                    }
                }
                
            } else {
                m[i] = 0;
            }
            ans.push_back(i);
        }
        return ans;
    }
};
