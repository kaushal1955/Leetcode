class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();
        vector<int> dp(n + 1, 0);
        
        auto isPalindrome = [&](int i, int j) {
            while (i < j) {
                if (s[i] != s[j]) return false;
                i++;
                j--;
            }
            return true;
        };
        
        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i - 1];
            for (int len = k; len <= k + 1; len++) {
                int start = i - len;
                if (start >= 0 && isPalindrome(start, i - 1)) {
                    dp[i] = max(dp[i], dp[start] + 1);
                }
            }
        }
        
        return dp[n];
    }
};