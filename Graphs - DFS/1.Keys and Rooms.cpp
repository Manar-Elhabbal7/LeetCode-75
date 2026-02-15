class Solution {
public:
    void dfs(int node, vector<bool>& visited, vector<vector<int>>& rooms) {
        visited[node] = true;
        for (auto neg : rooms[node]) {
            if (!visited[neg]) {
                dfs(neg, visited, rooms);
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n, 0);
        dfs(0,visited,rooms);

        for (auto val : visited) {
            if (!val)
                return false;
        }
        return true;
    }
};
