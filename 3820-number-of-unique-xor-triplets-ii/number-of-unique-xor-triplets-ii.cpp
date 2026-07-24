class Solution {
public:
    void fwht(vector<long long>& a) {
        int n = a.size();

        for (int len = 1; len < n; len <<= 1) {
            for (int i = 0; i < n; i += len * 2) {
                for (int j = 0; j < len; j++) {
                    long long x = a[i + j];
                    long long y = a[i + j + len];
                    a[i + j] = x + y;
                    a[i + j + len] = x - y;
                }
            }
        }
    }

    int uniqueXorTriplets(vector<int>& nums) {
        const int MAX = 2048;

        vector<long long> f(MAX, 0);

        for (int x : nums)
            f[x] = 1;

        fwht(f);

        for (int i = 0; i < MAX; i++)
            f[i] = f[i] * f[i] * f[i];

        fwht(f);

        int ans = 0;

        for (int i = 0; i < MAX; i++) {
            if (f[i] != 0)
                ans++;
        }

        return ans;
    }
};