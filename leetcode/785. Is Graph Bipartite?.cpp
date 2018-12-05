class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int nodes = graph.size();
        vector<int> color(nodes, -1);
        for(int i = 0; i < nodes; i++)
        {
            if(color[i] != -1)
            {
                continue;
            }
            color[i] = 0;
            queue<int> q;
            q.push(i);
            while(!q.empty())
            {
                int top = q.front();
                q.pop();
                for(int j = 0; j < graph[top].size(); j++)
                {
                    if(color[graph[top][j]] == -1)
                    {
                        color[graph[top][j]] = 1 - color[top];
                        q.push(graph[top][j]);
                    }
                    else
                    {
                        if(color[graph[top][j]] == color[top])
                        {
                           return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};