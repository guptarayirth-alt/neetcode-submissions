

class Solution {
    // Parent array to keep track of the sets
    std::vector<int> parent;

    // FIND function with Path Compression
    int find(int node) {
        if (parent[node] == node) {
            return node;
        }
        // Path compression: attach the node directly to the root
        return parent[node] = find(parent[node]); 
    }

public:
    std::vector<int> findRedundantConnection(std::vector<std::vector<int>>& edges) {
        int n = edges.size();
        
        // The graph nodes are 1-indexed (from 1 to N)
        parent.resize(n + 1);
        
        // Initially, every node is its own parent (its own separate set)
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
        
        // Iterate through all the edges
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            
            // Find the ultimate root parents of both nodes
            int rootU = find(u);
            int rootV = find(v);
            
            // If they share the same root parent, a cycle is detected!
            if (rootU == rootV) {
                return edge; // This is the redundant connection
            }
            
            // UNION: Otherwise, merge the two sets
            parent[rootU] = rootV;
        }
        
        // Fallback return (problem guarantees one redundant edge exists)
        return {}; 
    }
};