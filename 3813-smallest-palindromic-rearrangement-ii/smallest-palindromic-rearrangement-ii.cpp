class Solution {
public:
    const long long LIMIT = 1000001;   // k <= 1e6

    // Compute nCr with early stopping if result exceeds LIMIT
    long long C(int n, int r) {
        if (r > n) return 0;
        r = min(r, n - r);

        long long ans = 1;

        for (int i = 1; i <= r; i++) {
            ans = ans * (n - i + 1) / i;

            if (ans >= LIMIT)
                return LIMIT;
        }

        return ans;
    }

    // Count distinct permutations of remaining characters
    long long countPerm(vector<int>& cnt) {
        int total = 0;

        for (int x : cnt)
            total += x;

        long long ans = 1;

        for (int x : cnt) {
            if (x == 0)
                continue;

            ans *= C(total, x);

            if (ans >= LIMIT)
                return LIMIT;

            total -= x;
        }

        return ans;
    }

    string smallestPalindrome(string s, int k) {

        vector<int> cnt(26, 0);

        // Count frequency
        for (char c : s)
            cnt[c - 'a']++;

        string mid = "";

        // Store middle character (if any)
        // Convert frequency to half frequency
        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2)
                mid.push_back(char('a' + i));

            cnt[i] /= 2;
        }

        // Total possible palindromes
        if (countPerm(cnt) < k)
            return "";

        string left = "";

        int len = s.size() / 2;

        // Construct left half
        for (int pos = 0; pos < len; pos++) {

            for (int c = 0; c < 26; c++) {

                if (cnt[c] == 0)
                    continue;

                // Try using this character
                cnt[c]--;

                long long ways = countPerm(cnt);

                if (ways >= k) {
                    // This character belongs to answer
                    left.push_back(char('a' + c));
                    break;
                }

                // Skip these permutations
                k -= ways;

                // Restore
                cnt[c]++;
            }
        }

        // Build right half
        string right = left;
        reverse(right.begin(), right.end());

        return left + mid + right;
    }
};