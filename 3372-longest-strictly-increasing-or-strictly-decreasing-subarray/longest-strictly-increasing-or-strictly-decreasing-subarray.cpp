class Solution {
public:
    int longestMonotonicSubarray(std::vector<int>& nums) {
        if (nums.empty()) return 0;
        
        int maxLength = 1;
        int incLen = 1;
        int decLen = 1;
        
        for (size_t i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[i - 1]) {
                incLen++;
                decLen = 1;
            } else if (nums[i] < nums[i - 1]) {
                decLen++;
                incLen = 1;
            } else {
                incLen = 1;
                decLen = 1;
            }
            
            maxLength = std::max({maxLength, incLen, decLen});
        }
        
        return maxLength;
    }
};