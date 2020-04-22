class Solution {
public:
    vector<bool> visited;
    vector< vector<int> > adj;
    void dfs(int room) {
        visited[room] = true;
        for(auto i : adj[room]) {
            if(!visited[i]) {
                dfs(i);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        visited.resize(n, false);
        adj.resize(n);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < rooms[i].size(); j++) {
                adj[i].push_back(rooms[i][j]);
            }
        }
        dfs(0);
        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                return false;
            }
        }
        return true;
    }
};
