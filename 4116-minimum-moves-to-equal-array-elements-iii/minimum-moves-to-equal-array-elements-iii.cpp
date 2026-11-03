class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mx = nums[0];
        long long sum = nums[0];
        
        for (size_t i = 1; i < nums.size(); ++i) {
            mx =max(mx, nums[i]);
            sum += nums[i];
        }
        
        return (mx * nums.size()) - sum;
    }
};