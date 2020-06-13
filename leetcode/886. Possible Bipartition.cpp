class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector< vector<int> > adj(N + 1);
        vector<int> color(N + 1, 0);
        vector<bool> visited(N + 1, false);
        for(auto &i : dislikes) {
            int u = i[0];
            int v = i[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(int i = 1; i <= N; i++) {
            if(!visited[i]) {
                queue<int> q;
                q.push(i);
                color[i] = 1;
                while(!q.empty()) {
                    int top = q.front();
                    q.pop();
                    if(visited[top]) {
                        continue;
                    }
                    visited[top] = true;
                    for(auto it : adj[top]) {
                        if(color[top] == color[it]) {
                            return false;
                        }
                        if(color[top] == 1) {
                            color[it] = 2;
                        } else {
                            color[it] = 1;
                        }
                        q.push(it);
                    }
                }
            }
        }
        return true;
    }
};
