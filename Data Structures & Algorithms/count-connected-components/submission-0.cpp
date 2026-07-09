class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
// connect in a neignbour map then 
unordered_map< int, vector<int>> graph;
for( int i =0; i< n; i++)
{
    graph[i]={};
}
for( auto edge : edges)
{
    int a = edge[0];
    int b= edge[1];
    graph[a].push_back(b);
 graph[b].push_back(a);
}
  vector<bool> visited(n, false);
        int count = 0;

        // Step 3: Traverse every node; whenever we hit an unvisited one,
        // it means a "break" (new component) -> increase count and DFS from there
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                count++;
                dfs(i, graph, visited);
            }
        }

        return count;
    
    }
    private:
    void dfs(int node, unordered_map<int, vector<int>>& graph, vector<bool>& visited) {
        visited[node] = true;

        for (int neighbour : graph[node]) {
            if (!visited[neighbour]) {
                dfs(neighbour, graph, visited);
            }
        }
    }
};
