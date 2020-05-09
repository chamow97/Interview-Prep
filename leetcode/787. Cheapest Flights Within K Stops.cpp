class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector< vector< pair<int, int> > > adj(n);
        for(int i = 0; i < flights.size(); i++) {
            int u = flights[i][0];
            int v = flights[i][1];
            int w = flights[i][2];
            adj[u].push_back({v, w});
        }
        vector< vector<int> > distance(n, vector<int>(K + 2, 1e9));
        for(int i = 0; i <= K; i++) {
            distance[src][i] = 0;
        }
        queue< pair<int, int> > q;
        q.push({src, 0});
        while(!q.empty()) {
            pair<int, int> top = q.front();
            q.pop();
            int u = top.first;
            int stops = top.second;
            if(stops > K) {
                continue;
            }
            for(auto i : adj[u]) {
                int v = i.first;
                int w = i.second;
                if(distance[v][stops + 1] > distance[u][stops] + w) {
                    distance[v][stops + 1] = distance[u][stops] + w;
                    q.push({v, stops + 1});
                }
            }
        }
        int minDist = INT_MAX;
        for(auto i : distance[dst]) {
            minDist = min(minDist, i);
        }
        return minDist == 1e9 ? -1 : minDist;
    }
};
