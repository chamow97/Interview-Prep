class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack< pair<char, int> > ans;
        ans.push({'#', 1});
        for(int i = 0; i < s.length(); i++) {
            if(ans.top().first == s[i]) {
                int oldFreq = ans.top().second;
                if(oldFreq == k - 1) {
                    ans.pop();
                } else {
                    ans.pop();
                    ans.push({s[i], oldFreq + 1});
                }
            } else {
                ans.push({s[i], 1});
            }
        }
        string ansS = "";
        while(!ans.empty()) {
            if(ans.top().first == '#') {
                ans.pop();
                continue;
            }
            for(int i = 0; i < ans.top().second; i++)
                ansS += ans.top().first;
            ans.pop();
        }
        reverse(ansS.begin(), ansS.end());
        return ansS;
    }
};
