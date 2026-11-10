class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<long long> f(n + 1, 1e18);
        f[0] = 0;
        
        for (int i = 1; i <= n; ++i) {
            long long x = costs[i - 1];
            for (int j = max(0, i - 3); j < i; ++j) {
                long long jumpCost = (long long)(i - j) * (i - j);
                f[i] = min(f[i], f[j] + x + jumpCost);
            }
        }
        
        return f[n];
    }
};