class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        int startX = 0, startY = 0;
        int litterCount = 0;

        // Store an index for every litter cell
        vector<vector<int>> id(m, vector<int>(n, -1));

        // Find starting position and assign IDs to litter
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (classroom[i][j] == 'S') {
                    startX = i;
                    startY = j;
                }
                else if (classroom[i][j] == 'L') {
                    id[i][j] = litterCount++;
                }
            }
        }

        // No litter
        if (litterCount == 0)
            return 0;

        int totalMasks = 1 << litterCount;

        /*
            State:
            (row, col, remainingEnergy, mask)

            mask:
            1 -> litter still needs to be collected
            0 -> litter already collected
        */

        vector<vector<vector<vector<bool>>>> visited(
            m,
            vector<vector<vector<bool>>>(
                n,
                vector<vector<bool>>(
                    energy + 1,
                    vector<bool>(totalMasks, false)
                )
            )
        );

        // Initially all litter is uncollected
        int startMask = totalMasks - 1;

        queue<tuple<int, int, int, int>> q;

        q.push({startX, startY, energy, startMask});

        visited[startX][startY][energy][startMask] = true;

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        int moves = 0;

        while (!q.empty()) {

            int size = q.size();

            while (size--) {

                auto [x, y, curEnergy, mask] = q.front();
                q.pop();

                // All litter collected
                if (mask == 0)
                    return moves;

                // Cannot move with zero energy
                if (curEnergy == 0)
                    continue;

                for (int k = 0; k < 4; k++) {

                    int nx = x + dx[k];
                    int ny = y + dy[k];

                    // Check boundaries
                    if (nx < 0 || nx >= m ||
                        ny < 0 || ny >= n)
                        continue;

                    // Obstacle
                    if (classroom[nx][ny] == 'X')
                        continue;

                    int newEnergy = curEnergy - 1;
                    int newMask = mask;

                    // Reset area
                    if (classroom[nx][ny] == 'R') {
                        newEnergy = energy;
                    }

                    // Litter
                    if (classroom[nx][ny] == 'L') {
                        int idx = id[nx][ny];

                        // Mark this litter as collected
                        newMask &= ~(1 << idx);
                    }

                    // Visit this state only once
                    if (!visited[nx][ny][newEnergy][newMask]) {

                        visited[nx][ny][newEnergy][newMask] = true;

                        q.push({
                            nx,
                            ny,
                            newEnergy,
                            newMask
                        });
                    }
                }
            }

            moves++;
        }

        return -1;
    }
};