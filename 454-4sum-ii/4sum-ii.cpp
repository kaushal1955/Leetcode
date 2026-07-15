class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2,
                     vector<int>& nums3, vector<int>& nums4) {

        unordered_map<int, int> mp;

        // Store sums of nums1 and nums2
        for (int a : nums1) {
            for (int b : nums2) {
                mp[a + b]++;
            }
        }

        int ans = 0;

        // Find complementary sums
        for (int c : nums3) {
            for (int d : nums4) {
                ans += mp[-(c + d)];
            }
        }

        return ans;
    }
};