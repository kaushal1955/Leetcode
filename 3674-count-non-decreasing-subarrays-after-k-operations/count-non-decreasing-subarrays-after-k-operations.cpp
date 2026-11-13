
class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        deque<pair<int, int>> dq;

        long long ans = 0;
        long long cost = 0;
        int right = n - 1;

        for (int i = n - 1; i >= 0; i--) {
            int count = 1;

            while (!dq.empty() && dq.back().first < nums[i]) {
                int val = dq.back().first;
                int freq = dq.back().second;
                dq.pop_back();

                count += freq;
                cost += 1LL * (nums[i] - val) * freq;
            }

            dq.push_back({nums[i], count});

            while (cost > k) {
                int val = dq.front().first;
                int freq = dq.front().second;
                dq.pop_front();

                cost -= val - nums[right];
                right--;

                if (freq > 1) {
                    dq.push_front({val, freq - 1});
                }
            }

            ans += right - i + 1;
        }

        return ans;
    }
};
