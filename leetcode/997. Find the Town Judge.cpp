class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> maps(N + 1, 0);
        for(int i = 0; i < trust.size(); i++) {
            maps[trust[i][1]]++;
            maps[trust[i][0]]--;
        }
        for(int i = 1; i <= N; i++) {
            if(maps[i] == N - 1) {
                return i;
            }
        }
        return -1;
    }
};
