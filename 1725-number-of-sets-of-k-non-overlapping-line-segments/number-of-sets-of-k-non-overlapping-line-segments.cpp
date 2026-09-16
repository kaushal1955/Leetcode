class Solution {
public:
    int numberOfSets(int n, int k) {
        const int MOD = 1e9 + 7;

        vector<vector<long long>> dp(n, vector<long long>(k + 1, 0));
        for (int i = 0; i < n; i++) {
            dp[i][0] = 1;
        }
        for (int segments = 1; segments <= k; segments++) {
            long long sum = 0;

            for (int points = 1; points < n; points++) {
                sum = (sum + dp[points - 1][segments - 1]) % MOD;

                dp[points][segments] =
                    (dp[points - 1][segments] + sum) % MOD;
            }
        }

        return dp[n - 1][k];
    }
};