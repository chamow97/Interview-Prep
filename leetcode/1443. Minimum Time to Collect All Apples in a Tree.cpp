class Solution {
public:
    int ans;
    void dfs(int s, vector< vector<int> > &adj, vector<bool> &hasApple, vector<bool> &visited, vector<int> &values) {
        visited[s] = true;
        for(auto i : adj[s]) {
            if(!visited[i]) {
                dfs(i, adj, hasApple, visited, values);        
                if(hasApple[i]) {
                    values[s] += (2 + values[i]);
                } else {
                    if(values[i] > 0) {
                        values[s] += (2 + values[i]);
                    }
                }
            }
        }
    }
    
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector< vector<int> > adj(n, vector<int>(0));
        for(int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool> visited(n, false);
        vector<int> values(n, 0);
        dfs(0, adj, hasApple, visited, values);
        fill(visited.begin(), visited.end(), false);
        return values[0];
    }
};
