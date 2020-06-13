class Solution {
public:
    
    void dfs(int u, int v, vector< vector<int> > &adj, bool &possible, vector<bool> &visited) {
        visited[u] = true;
        if(u == v) {
            possible = true;
        }
        for(auto i : adj[u]) {
            if(!visited[i]) {
                dfs(i, v, adj, possible, visited);
            }
        }
    }
    
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<bool> visited(n, false);
        vector< vector<int> > adj(n);
        for(auto i : prerequisites) {
            adj[i[0]].push_back(i[1]);
        }
        vector<bool> ans;
        map<pair<int, int>, bool> ms;
        for(auto i : queries) {
            int u = i[0];
            int v = i[1];
            bool possible = false;
            if(ms.find({u, v}) != ms.end()) {
                possible = ms[{u, v}];
            } else {
                fill(visited.begin(), visited.end(), false);
                dfs(u, v, adj, possible, visited);   
            }
            ms[{u, v}] = possible;
            ans.push_back(ms[{u, v}]);
        }
        return ans;
    }
};
