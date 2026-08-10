int dp[100001];
class Solution {
public:
    int solve(int n){
        if(n==0){
            return 0;
        }
        if(dp[n] !=-1){
            return dp[n];
        }
        for(int i=1;i*i<=n;i++){
            int val=solve(n-i*i);
            if(val==0){
                return dp[n]=1;
            }
        }
        return dp[n]=0;
    }
    bool winnerSquareGame(int n) {
        memset(dp,-1,sizeof dp);
        return solve(n);
    }
};