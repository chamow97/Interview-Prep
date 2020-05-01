class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue< pair< pair<int, int>, int > > q;
        // add rotting orange's location
        int n = grid.size();
        int m = grid[0].size();
        int X[4] = {-1, 0, 0, 1};
        int Y[4] = {0, -1, 1, 0};
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                }
            }
        }
        int maxDist = 0;
        while(!q.empty()) {
            pair< pair<int, int>, int > curr = q.front();
            q.pop();
            int x = curr.first.first;
            int y = curr.first.second;
            int distance = curr.second;
            if(grid[x][y] == 1)
            maxDist = max(maxDist, distance);
            // mark as visited
            grid[x][y] = 0;
            for(int i = 0; i < 4; i++) {
                int xCoord = X[i] + x;
                int yCoord = Y[i] + y;
                if(xCoord < 0 || xCoord >= n || yCoord < 0 || yCoord >= m || grid[xCoord][yCoord] != 1) {
                    continue;
                }
                q.push({{xCoord, yCoord}, distance + 1});
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    return -1;
                }
            }
        }
        return maxDist;
    }
};
