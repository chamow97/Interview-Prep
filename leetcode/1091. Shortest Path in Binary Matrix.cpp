class Solution {
public:
    int x1[8];
    int y1[8];
    int answer;
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int ptr = 0;
        for(int i = -1; i <= 1; i++) {
            for(int j = -1; j <= 1; j++) {
                if(i == 0 && j == 0) {
                    continue;
                }
                x1[ptr] = i;
                y1[ptr] = j;
                ptr++;
            }    
        }
        int n = grid.size();
        answer = INT_MAX;
        queue< pair< int, int > > q;
        if(grid[0][0] == 0) {
            q.push(make_pair(0, 0));
            grid[0][0] = 1;    
        }
        while(!q.empty()) {
            pair< int, int > curr = q.front();
            q.pop();
            int x = curr.first;
            int y = curr.second;
            if(x == n - 1 && y == n - 1) {
                return grid[x][y];
            }
            for(int i = 0; i < 8; i++) {
                int X = x + x1[i];
                int Y = y + y1[i];
                if(X < 0 || X >= n || Y < 0 || Y >= n || grid[X][Y] != 0){
                    continue;
                }
                q.push(make_pair(X, Y));
                grid[X][Y] = grid[x][y] + 1;
            }
        }
        return -1;
    }
};
