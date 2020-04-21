class Solution {
public:
    int n;
    vector<int> visited;
    bool dfs(int s, vector<int> adj[])
    {
        visited[s] = 1;
        vector<int>::iterator it;
        for(it = adj[s].begin(); it != adj[s].end(); it++)
        {
            int i = *it;
            if(visited[i] == 1)
            {
                return true;
            }
            if(visited[i] == 0 && dfs(i, adj))
            {
                return true;
            }
        }
        visited[s] = 2;
        return false;
    }
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        n = numCourses;
        visited.resize(n, 0);
        vector<int> adj[n];
        for(int i = 0; i < prerequisites.size(); i++)
        {
            adj[prerequisites[i].first].push_back(prerequisites[i].second);
        }
        for(int i = 0; i < n; i++)
        {
            if(!visited[i])
            {
                if(dfs(i, adj))
                {
                    return false;
                }
            }
        }
        return true;
    }
};
