
class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        
        long long maxLcm = 1;
        int mx = 0;

        for (int x : nums) {
            maxLcm = lcm(maxLcm, (long long)x);
            mx = max(mx, x);
        }

        long long limit = maxLcm * mx;

        for (int i = 0; i < n; i++) {

            long long prod = 1;
            long long g = 0;
            long long l = 1;

            for (int j = i; j < n; j++) {

                prod *= nums[j];

                g = gcd(g, (long long)nums[j]);

                l = lcm(l, (long long)nums[j]);

             
                if (prod == g * l) {
                    ans = max(ans, j - i + 1);
                }

               
                if (prod > limit) {
                    break;
                }
            }
        }

        return ans;
    }
};
