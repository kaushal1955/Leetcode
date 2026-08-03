class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        // dp[i] = best score difference (current player - opponent) 
        // achievable from index i to end
        vector<int> dp(n + 1, 0);
        
        for (int i = n - 1; i >= 0; i--) {
            int best = INT_MIN;
            int total = 0;
            for (int k = 1; k <= 3 && i + k - 1 < n; k++) {
                total += stoneValue[i + k - 1];
                best = max(best, total - dp[i + k]);
            }
            dp[i] = best;
        }
        
        if (dp[0] > 0) return "Alice";
        else if (dp[0] < 0) return "Bob";
        else return "Tie";
    }
};