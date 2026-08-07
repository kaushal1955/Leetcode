#include <string>
#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
public:
    std::string smallestNumber(std::string num, long long t) {
        long long temp = t;
        for (int i = 2; i <= 9; ++i) {
            while (temp % i == 0) temp /= i;
        }
        if (temp > 1) return "-1";

        int n = num.length();
        std::vector<long long> rem(n + 1, 0);
        rem[0] = t;
        int pos = n - 1;

        for (int i = 0; i < n; ++i) {
            if (num[i] == '0') {
                pos = i;
                break;
            }
            rem[i + 1] = rem[i] / std::gcd(rem[i], (long long)(num[i] - '0'));
        }

        if (rem[n] == 1 && pos == n - 1 && num[pos] != '0')
            return num;

        for (int i = pos; i >= 0; --i) {
            int startDigit = (i < n ? (num[i] - '0') + 1 : 1);

            for (int d = startDigit; d <= 9; ++d) {
                long long now = rem[i] / std::gcd(rem[i], (long long)d);

                std::string suffix = "";
                long long curr = now;

                for (int j = n - 1; j > i; --j) {
                    for (int v = 9; v >= 1; --v) {
                        if (curr % v == 0) {
                            suffix += std::to_string(v);
                            curr /= v;
                            break;
                        }
                    }
                }

                if (curr == 1) {
                    std::reverse(suffix.begin(), suffix.end());
                    return num.substr(0, i) + std::to_string(d) + suffix;
                }
            }
        }

        long long curr = t;
        std::string digits = "";

        for (int v = 9; v >= 2; --v) {
            while (curr % v == 0) {
                digits += std::to_string(v);
                curr /= v;
            }
        }

        std::sort(digits.begin(), digits.end());

        int reqLen = std::max(n + 1, (int)digits.length());
        return std::string(reqLen - digits.length(), '1') + digits;
    }
};