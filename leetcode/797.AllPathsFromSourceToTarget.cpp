class Solution {
public:
    bool visited[1000];
    int path[1000];
    int path_index = 0;
    vector<int> ans;
    vector< vector<int> > total;
    void getP(int u, int d, vector<vector<int>>& graph)
    {
        visited[u] = true;
        path[path_index] = u;
        path_index++;

        if (u == d)
        {
            for (int i = 0; i<path_index; i++)
                ans.push_back(path[i]);
            total.push_back(ans);
            ans.resize(0);
        }
        else 
        {
            vector<int>::iterator i;
            for (i = graph[u].begin(); i != graph[u].end(); ++i)
                if (!visited[*i])
                    getP(*i, d, graph);
        }

        path_index--;
        visited[u] = false;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        getP(0, n-1, graph);
        return total;
    }
};