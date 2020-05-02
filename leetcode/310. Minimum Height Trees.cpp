class Solution {
public:
    int maxDepth;
    int farthestNode;
    void dfs(int s, vector<bool> &visited, vector< vector<int> > &adj, int currDepth, vector<int> &path) {
        visited[s] = true;
        if(maxDepth < currDepth) {
            maxDepth = currDepth;
            farthestNode = s;
        }
        for(auto i : adj[s]) {
            if(!visited[i]) {
                path[i] = s;
                dfs(i, visited, adj, currDepth + 1, path);
            }
        }
    }
    
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        // find any leaf node and store the nodes based on the height
        // while finding the diameter of the tree
        // output the nodes with middle height
        vector< vector<int> > adj(n, vector<int>(0));
        for(int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        // resetting values
        
        farthestNode = 0;
        maxDepth = 0;
        vector<int> path(n, -1);
        vector<bool> visited(n, false);
        
        // first DFS to find any leaf node
        dfs(0, visited, adj, 0, path);
        
        // resetting the values for next DFS which finds the diameter and its path
        maxDepth = -1;
        fill(visited.begin(), visited.end(), false);
        fill(path.begin(), path.end(), -1);
        dfs(farthestNode, visited, adj, 0, path);
        
        // finding the middle node by traversing the path
        int u = farthestNode;
        int currDepth = 0;
        vector<int> result;
        while(u != -1) {
            if(maxDepth % 2) {
                if(currDepth == (maxDepth / 2) || currDepth == ((maxDepth + 1) / 2)) {
                    result.push_back(u);
                }
            } else {
                if(currDepth == (maxDepth / 2)) {
                    result.push_back(u);
                }
            }
            currDepth++;
            u = path[u];
        }
        return result;
    }
};
