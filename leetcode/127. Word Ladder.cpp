class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue< pair<string, int> > q;
        unordered_map<string, bool> m;
        for(auto i : wordList) {
            m[i] = true;
        }
        q.push({beginWord, 1});
        int ans = INT_MAX;
        while(!q.empty()) {
            pair<string, int> p = q.front();
            q.pop();
            string curr = p.first;
            int step = p.second;
            if(curr == endWord) {
                ans = min(ans, step);
            } else {
                for(int i = 0; i < curr.length(); i++) {
                    for(int j = 0; j < 26; j++) {
                        string currWord = curr;
                        currWord[i] = (char)(j + 'a');
                        if(m[currWord] == true && currWord != curr) {
                            m[currWord] = false;
                            q.push({currWord, step + 1});
                        }
                    }
                }
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};
