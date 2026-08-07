#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string smallestNumber(string num, long long t) {
        long long temp = t;
        for (int i = 2; i <= 9; i++) {
            while (temp % i == 0)
                temp /= i;
        }

        if (temp > 1)
            return "-1";

        int n = num.length();
        vector<long long> rem(n + 1, t);

        int pos = num.find('0');
        if (pos == string::npos)
            pos = n - 1;

        for (int i = 0; i < n; i++) {
            if (num[i] == '0')
                break;

            rem[i + 1] = rem[i] / gcd(rem[i], (long long)(num[i] - '0'));
        }

        if (num.find('0') == string::npos && rem[n] == 1)
            return num;

        for (int i = pos; i >= 0; i--) {
            int startDigit = num[i] - '0' + 1;

            for (int d = startDigit; d <= 9; d++) {
                long long now = rem[i] / gcd(rem[i], (long long)d);

                string suffix = "";
                long long curr = now;

                for (int j = n - 1; j > i; j--) {
                    bool found = false;

                    for (int v = 9; v >= 2; v--) {
                        if (curr % v == 0) {
                            suffix.push_back(char('0' + v));
                            curr /= v;
                            found = true;
                            break;
                        }
                    }

                    if (!found)
                        suffix.push_back('1');
                }

                if (curr == 1) {
                    reverse(suffix.begin(), suffix.end());
                    return num.substr(0, i) + char('0' + d) + suffix;
                }
            }
        }

        long long curr = t;
        string digits = "";

        for (int v = 9; v >= 2; v--) {
            while (curr % v == 0) {
                digits.push_back(char('0' + v));
                curr /= v;
            }
        }

        if (curr != 1)
            return "-1";

        sort(digits.begin(), digits.end());

        int reqLen = max(n + 1, (int)digits.size());

        return string(reqLen - digits.size(), '1') + digits;
    }
};