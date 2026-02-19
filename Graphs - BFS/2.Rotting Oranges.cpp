
class Solution {
public:
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    bool isValid(int x, int y, int n, int m) {
        return x >= 0 and x < n and y >= 0 and y < m;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int ans = -1;
        int n = grid.size(), m = grid[0].size();

        bool allEmpty = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] != 0) {
                    allEmpty = false;
                    break;
                }
            }
        }

        if (allEmpty)
            return 0;

        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }

        while (!q.empty()) {
            int sz = q.size();
            
            while(sz--) {
                auto [x, y] = q.front();
                q.pop();

                for (int j = 0; j < 4; j++) {
                    int newX = x + dx[j];
                    int newY = y + dy[j];

                    if (isValid(newX, newY, n, m) and grid[newX][newY] == 1) {
                        grid[newX][newY] = 2;
                        q.push({newX, newY});
                    }
                }
            }
            ans++;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1)
                    return -1;
            }
        }
        return ans;
    }
};
//Beat 100% ^_^
