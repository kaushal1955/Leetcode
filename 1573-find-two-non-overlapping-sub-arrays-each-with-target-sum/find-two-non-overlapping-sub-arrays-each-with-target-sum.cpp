class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> minLen(n, INT_MAX);
        int result = INT_MAX;
        int left = 0, sum = 0;
        
        for (int right = 0; right < n; right++) {
            sum += arr[right];
            
            while (sum > target) {
                sum -= arr[left];
                left++;
            }
            
            if (sum == target) {
                int currLen = right - left + 1;
                
                if (left > 0 && minLen[left - 1] != INT_MAX) {
                    result = min(result, currLen + minLen[left - 1]);
                }
                
                minLen[right] = currLen;
            }
            
            if (right > 0) {
                minLen[right] = min(minLen[right], minLen[right - 1]);
            }
        }
        
        return result == INT_MAX ? -1 : result;
    }
};