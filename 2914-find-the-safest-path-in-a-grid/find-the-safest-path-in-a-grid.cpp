class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<int>> dist(n, vector<int>(n, -1));
        queue<pair<int, int>> q;

        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == 1) {
                    dist[r][c] = 0;
                    q.push({r, c});
                }
            }
        }

        int dirs[5] = {1, 0, -1, 0, 1};

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nr = r + dirs[i];
                int nc = c + dirs[i + 1];

                if (nr >= 0 && nr < n && nc >= 0 && nc < n && dist[nr][nc] == -1) {
                    dist[nr][nc] = dist[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }

        priority_queue<array<int, 3>> pq;
        vector<vector<bool>> seen(n, vector<bool>(n, false));

        pq.push({dist[0][0], 0, 0});

        while (!pq.empty()) {
            auto [safe, r, c] = pq.top();
            pq.pop();

            if (seen[r][c]) continue;
            seen[r][c] = true;

            if (r == n - 1 && c == n - 1) {
                return safe;
            }

            for (int i = 0; i < 4; i++) {
                int nr = r + dirs[i];
                int nc = c + dirs[i + 1];

                if (nr >= 0 && nr < n && nc >= 0 && nc < n && !seen[nr][nc]) {
                    int nextSafe = min(safe, dist[nr][nc]);
                    pq.push({nextSafe, nr, nc});
                }
            }
        }

        return 0;
    }
};