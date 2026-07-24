class Solution {
public:
    vector<int> findOrder(int N, vector<vector<int>>& arr) {
        vector<vector<int>> adj(N);
        vector<int> indegree(N, 0);

        for (int i = 0; i < (int)arr.size(); i++) {
            int a = arr[i][0];   // course
            int b = arr[i][1];   // prerequisite
            adj[b].push_back(a); // b -> a (finishing b unlocks a)
            indegree[a]++;
        }

        queue<int> q;
        for (int i = 0; i < N; i++) {
            if (indegree[i] == 0) q.push(i);
        }

        vector<int> topo;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for (auto it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }

        if ((int)topo.size() != N) return {};   // cycle detected
        return topo;
    }
};