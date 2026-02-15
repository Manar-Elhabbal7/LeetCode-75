class Solution {
public:
    // Number of connected components
    void dfs(int node, vector<bool>& visited, vector<vector<int>>& mat) {
        visited[node] = true;
        for (int i = 0; i < mat.size(); i++) {
            if (mat[node][i] == 1 and !visited[i]) {
                dfs(i, visited, mat);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected[0].size();
        vector<bool> visited(n + 1, false);
        int cnt{0};

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(i, visited, isConnected);
                cnt++;
            }
        }
        return cnt;
    }
};
