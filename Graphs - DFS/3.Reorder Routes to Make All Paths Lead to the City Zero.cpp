class Solution {
public:
    // how cost to reach from node to node 0
    int dfs(int node, vector<vector<pair<int, int>>>& graph,
            vector<bool>& visited) {

        visited[node] = true;
        int totalCost = 0;

        for (const auto& [child, cost] : graph[node]) {
            if (!visited[child]) {
                totalCost += cost + dfs(child, graph, visited);
            }
        }
        return totalCost;
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<bool> visited(n, false);
        vector<vector<pair<int, int>>> weightedEges(n);

        for (const auto& conn : connections) {
            int u = conn[0];
            int v = conn[1];
            weightedEges[u].emplace_back(v, 1);
            weightedEges[v].emplace_back(u, 0);
        }

        return dfs(0, weightedEges, visited);
    }
};
