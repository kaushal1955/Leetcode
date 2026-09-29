class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if ((m + n - 1) % 2 != 0) return false;
        if (grid[0][0] == ')' || grid[m-1][n-1] == '(') return false;

        vector<vector<set<int>>> dp(m, vector<set<int>>(n));
        dp[0][0].insert(1);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) continue;

                set<int> cur;
                if (j > 0) {
                    for (int bal : dp[i][j-1]) cur.insert(bal);
                }
                if (i > 0) {
                    for (int bal : dp[i-1][j]) cur.insert(bal);
                }

                for (int bal : cur) {
                    if (grid[i][j] == '(') {
                        dp[i][j].insert(bal + 1);
                    } else {
                        if (bal - 1 >= 0) dp[i][j].insert(bal - 1);
                    }
                }
            }
        }

        return dp[m-1][n-1].count(0) > 0;
    }
};