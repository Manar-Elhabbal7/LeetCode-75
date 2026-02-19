class Solution {
public:
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size(), m = maze[0].size();
        int steps{0};

        vector<vector<bool>> visited(n, vector<bool>(m, false));
        queue<pair<int, int>> q;

        q.push({entrance[0], entrance[1]});
        visited[entrance[0]][entrance[1]] = true;
        

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                auto [tx, ty] = q.front();
                q.pop();

                // shortest path
                if ((tx == 0 or tx == n - 1 or ty == 0 or ty == m - 1) and
                    !(tx == entrance[0] and ty == entrance[1])) {
                    return steps;
                }

                for (int i = 0; i < 4; i++) {
                    int newX = dx[i] + tx;
                    int newY = dy[i] + ty;

                    if (newX >= 0 and newX < n and newY >= 0 and newY < m and
                        maze[newX][newY] == '.' and !visited[newX][newY]) {
                        q.push({newX, newY});
                        visited[newX][newY] = true;
                    }
                }
            }
            // after finish any level
            steps++;
        }
        return -1;
    }
};
