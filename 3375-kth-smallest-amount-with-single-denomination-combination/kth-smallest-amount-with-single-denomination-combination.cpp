class Solution {
public:

    long long findKthSmallest(vector<int>& coins, int k) {

        int n = coins.size();

        auto countNumbers = [&](long long x) {

            long long count = 0;

            // Enumerate every non-empty subset
            for (int mask = 1; mask < (1 << n); mask++) {

                long long L = 1;

                for (int i = 0; i < n; i++) {

                    if (mask & (1 << i)) {

                        L = std::lcm(L, (long long)coins[i]);

                        // L is already too large
                        if (L > x) {
                            break;
                        }
                    }
                }

                // Number of selected coins
                int bits = __builtin_popcount(mask);

                if (bits % 2 == 1) {
                    count += x / L;
                }
                else {
                    count -= x / L;
                }
            }

            return count;
        };

        // Smallest possible answer
        long long left = 1;

        // kth multiple of the smallest coin
        long long right =
            1LL * k * (*min_element(coins.begin(), coins.end()));

        while (left < right) {

            long long mid =
                left + (right - left) / 2;

            if (countNumbers(mid) >= k) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }

        return left;
    }
};