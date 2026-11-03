class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=nums.size();
        int mx=0;
        long long sum=0;
        for(int x:nums){
            mx=max(mx,x);
            sum +=x;
        }
        return (mx*n)-sum;

    }
};