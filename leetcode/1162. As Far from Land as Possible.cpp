class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        queue<pair< pair<int, int>, int> > q;
        int X[] = {-1, 0, 0, 1};
        int Y[] = {0, -1, 1, 0};
        int zero = 0, ones = 0;
        int n = grid.size();
        int m = grid[0].size();
        int maxi = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    q.push({{i, j}, 0});
                    ones++;
                } else {
                    zero++;
                }
            }
        }
        if(ones == n * m || zero == n * m) {
            return -1;
        }
        while(!q.empty()) {
            pair< pair<int, int>, int> top = q.front();
            q.pop();
            int x = top.first.first;
            int y = top.first.second;
            int dist = top.second;
            for(int i = 0; i < 4; i++) {
                int xCoord = x + X[i];
                int yCoord = y + Y[i];
                if(xCoord >= 0 && xCoord < n && yCoord >= 0 && yCoord < m && grid[xCoord][yCoord] != 1) {
                    q.push({{xCoord, yCoord}, dist + 1});
                    maxi = max(maxi, dist + 1);
                    grid[xCoord][yCoord] = 1;
                }
            }
        }
        return maxi;
    }
};
