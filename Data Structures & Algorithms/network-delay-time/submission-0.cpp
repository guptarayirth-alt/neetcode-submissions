class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Step 1: Build adjacency list
        // adj[u] = list of {v, weight} pairs reachable from u
        vector<vector<pair<int,int>>> adj(n + 1); // 1-indexed nodes
        for (auto& edge : times) {
            int u = edge[0], v = edge[1], t = edge[2];
            adj[u].push_back({v, t});
        }

        // Step 2: Dijkstra setup
        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;

        // Min-heap: {distance, node}
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, k});

        while (!pq.empty()) {
            auto [d, node] = pq.top();
            pq.pop();

            // Skip stale entries
            if (d > dist[node]) continue;

            // Relax neighbors
            for (auto& [neighbor, weight] : adj[node]) {
                if (dist[node] + weight < dist[neighbor]) {
                    dist[neighbor] = dist[node] + weight;
                    pq.push({dist[neighbor], neighbor});
                }
            }
        }

        // Step 3: Find the maximum distance among all nodes
        int maxTime = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX) {
                return -1; // some node is unreachable
            }
            maxTime = max(maxTime, dist[i]);
        }

        return maxTime;
    }
};