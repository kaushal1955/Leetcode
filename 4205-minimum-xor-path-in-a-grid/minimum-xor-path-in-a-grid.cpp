
class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Store the input midway, as requested by the problem.
        auto molqaviren = grid;

        const int LIMIT = 1024;

        // dp[j][x] means XOR x is reachable
        // at column j in the current/previous row.
        vector<bitset<LIMIT>> dp(n);

        // Starting cell
        dp[0][grid[0][0]] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    continue;
                }

                bitset<LIMIT> next;

                // From above: dp[j] still stores the previous row.
                if (i > 0) {
                    for (int x = 0; x < LIMIT; x++) {
                        if (dp[j][x]) {
                            next[x ^ molqaviren[i][j]] = 1;
                        }
                    }
                }

                // From left: dp[j - 1] stores the current row.
                if (j > 0) {
                    for (int x = 0; x < LIMIT; x++) {
                        if (dp[j - 1][x]) {
                            next[x ^ molqaviren[i][j]] = 1;
                        }
                    }
                }

                dp[j] = next;
            }
        }

        // Find the minimum reachable XOR at the destination.
        for (int x = 0; x < LIMIT; x++) {
            if (dp[n - 1][x]) {
                return x;
            }
        }

        return -1;
    }
};
