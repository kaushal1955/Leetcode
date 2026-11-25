class Solution {
    static constexpr long long MOD1 = 1000000007LL;
    static constexpr long long MOD2 = 998244353LL;
    static constexpr long long BASE = 911382323LL;   

    int n;
    vector<int> a;

    static long long powmod(long long b, long long e, long long m) {
        long long r = 1;
        b %= m;
        while (e > 0) {
            if (e & 1) r = (long long)((__int128)r * b % m);
            b = (long long)((__int128)b * b % m);
            e >>= 1;
        }
        return r;
    }

    bool hasUnique(int L) {
        long long p1 = powmod(BASE, L - 1, MOD1);
        long long p2 = powmod(BASE, L - 1, MOD2);

        long long h1 = 0, h2 = 0;
        for (int i = 0; i < L; ++i) {
            long long x = a[i] + 1;
            h1 = (h1 * BASE + x) % MOD1;
            h2 = (h2 * BASE + x) % MOD2;
        }

        unordered_map<unsigned long long, int> cnt;   
        cnt.reserve((size_t)n * 2 + 1);
        auto key = [](long long x, long long y) {
            return ((unsigned long long)x << 32) ^ (unsigned long long)y;
        };

        cnt[key(h1, h2)] = 1;
        int ones = 1;                                

        for (int i = L; i < n; ++i) {
            long long out = a[i - L] + 1;             
            long long in  = a[i] + 1;                
            h1 = ((h1 - out * p1 % MOD1 + MOD1) * BASE + in) % MOD1;
            h2 = ((h2 - out * p2 % MOD2 + MOD2) * BASE + in) % MOD2;

            auto k = key(h1, h2);
            int c = cnt[k];                           
            if (c == 0)      { cnt[k] = 1; ++ones; }
            else if (c == 1) { cnt[k] = 2; --ones; }
        }
        return ones > 0;
    }

public:
    int smallestUniqueSubarray(vector<int>& nums) {
        n = (int)nums.size();
        a = nums;

        int lo = 1, hi = n;                         
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (hasUnique(mid)) hi = mid;             
            else                lo = mid + 1;         
        }
        return lo;
    }
};