class Solution {
public:
    int minimumSumSubarray(std::vector<int>& nums, int l, int r) {
        int n = nums.size();
        int ans = INT_MAX;
        
        for (int windowSize = l; windowSize <= r; ++windowSize) {
            int sum = 0;
            
            for (int i = 0; i < windowSize; ++i) {
                sum += nums[i];
            }
            if (sum > 0) {
                ans = std::min(ans, sum);
            }
            
            for (int i = windowSize; i < n; ++i) {
                sum -= nums[i - windowSize];
                sum += nums[i];
                
                if (sum > 0) {
                    ans = std::min(ans, sum);
                }
            }
        }
        
        return ans == INT_MAX ? -1 : ans;
    }
};