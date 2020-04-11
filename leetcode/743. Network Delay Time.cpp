#define INT_MAX 1e9

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector< pair<int, int> > adj[N + 1];
        int n = times.size();
        for(int i = 0; i < n; i++) {
            adj[times[i][0]].push_back({times[i][1], times[i][2]});
        }
        vector<int> distance(N + 1, INT_MAX);
        priority_queue< pair<int, int>, vector< pair<int, int> >,  greater< pair<int, int> > > pq;
        pq.push({0, K});
        distance[K] = 0;
        while(!pq.empty()) {
            pair<int, int> curr = pq.top();
            pq.pop();
            for(auto it : adj[curr.second]) {
                int u = curr.second;
                int v = it.first;
                int w = it.second;
                if(distance[v] > distance[u] + w) {
                    distance[v] = distance[u] + w;
                    pq.push({distance[v], v});
                }
            }
        }
        int maximum = 0;
        for(int i = 1; i <= N; i++) {
            if(i != K) {
                maximum = max(maximum, distance[i]);
            }
        }
        if(maximum == INT_MAX) {
            return -1;
        }
        return maximum;
    }
};
