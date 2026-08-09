int dp[101][201][2];

class Solution {
public:
    int solve(int i, int m, int turn, vector<int>& piles) {
        int n = piles.size();

        if (i == n)
            return 0;

        if (dp[i][m][turn] != -1)
            return dp[i][m][turn];

        // Alice's turn
        if (turn == 0) {
            int mx = 0;
            int sum = 0;

            for (int x = 1; x <= 2 * m; x++) {

                if (i + x - 1 >= n)
                    break;

                sum += piles[i + x - 1];

                int val = solve(i + x, max(m, x), 1, piles);

                mx = max(mx, sum + val);
            }

            return dp[i][m][turn] = mx;
        }

        // Bob's turn
        else {
            int mn = INT_MAX;

            for (int x = 1; x <= 2 * m; x++) {

                if (i + x - 1 >= n)
                    break;

                int val = solve(i + x, max(m, x), 0, piles);

                mn = min(mn, val);
            }

            return dp[i][m][turn] = mn;
        }
    }

    int stoneGameII(vector<int>& piles) {
        memset(dp, -1, sizeof(dp));

        return solve(0, 1, 0, piles);
    }
};