class Solution {
public:
    
    void dijkstras(int s, vector< vector< pair<int, int> > > &adj, vector<int> &distance) {
        priority_queue< pair<int, int>, vector< pair<int, int> >,  greater< pair<int, int> > > min_heap;
        min_heap.push(make_pair(0, s));
        distance[s] = 0;
        while(!min_heap.empty()) {
            int u = min_heap.top().second;
            min_heap.pop();
            vector< pair<int, int> > :: iterator it;
            for(it = adj[u].begin(); it != adj[u].end(); it++) {
                int v = (*it).first;
                int w = (*it).second;
                if(distance[v] > distance[u] + w) {
                    distance[v] = distance[u] + w;
                    min_heap.push(make_pair(distance[v], v));
                }
            }
        }
    }
    
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // Dijkstra's from each node
        vector< vector< pair<int, int> > > adj(n);
        for(int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back(make_pair(edges[i][1], edges[i][2]));
            adj[edges[i][1]].push_back(make_pair(edges[i][0], edges[i][2]));
        }
        int minimum = 1000000000;
        int minNode = -1;
        for(int i = 0; i < n; i++) {
            vector<int> distance(n, 1000000000);
            dijkstras(i, adj, distance);
            int currCount = 0;
            for(int j = 0; j < n; j++) {
                if(distance[j] <= distanceThreshold) {
                    currCount++;
                }
            }
            if(minimum >= currCount) {
                minimum = currCount;
                minNode = i;
            }
        }
        return minNode;
    }
};
