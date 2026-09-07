class Solution {
public:
    int distinctSubseqII(string s) {
        int const MOD=1e9+7;
        int n=s.size();
        vector<long long>last(26,-1);
        long long dp=1;
        for(int i=0;i<n;i++){
            int c=s[i]-'a';
            long long newDp = (2 * dp) % MOD;
            if (last[c] != -1) {
                newDp = (newDp - last[c] + MOD) % MOD;
            }
            last[c] = dp;
            dp = newDp;
        }
        return(int)((dp-1+MOD)%MOD);
    }
};