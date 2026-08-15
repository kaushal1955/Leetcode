class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n= nums.size();
        int totalXor=0;
        int zeroCount=0;

        for(int x:nums){
            totalXor ^=x;
            if(x==0){
                zeroCount++;
            }
        }
        if(totalXor !=0){
            return n;

        }
        if(zeroCount==n){
            return 0;
        }
        return n-1;
    }
};