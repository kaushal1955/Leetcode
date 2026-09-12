class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<tuple<int,int,int,int>> iv;
        for (int i = 0; i < n; ++i)
            iv.push_back({intervals[i][0], intervals[i][1], intervals[i][2], i});
        sort(iv.begin(), iv.end());
        
        vector<vector<pair<long long, vector<int>>>> memo(
            n, vector<pair<long long, vector<int>>>(5, {-1, {}}));
        
        function<pair<long long, vector<int>>(int, int)> dp = [&](int i, int quota) -> pair<long long, vector<int>> {
            if (i == n || quota == 0) return {0, {}};
            if (memo[i][quota].first != -1) return memo[i][quota];
            
            auto skip = dp(i + 1, quota);
            
            auto [l, r, w, origIdx] = iv[i];
            int lo = i + 1, hi = n;
            while (lo < hi) {
                int mid = (lo + hi) / 2;
                if (get<0>(iv[mid]) > r) hi = mid;
                else lo = mid + 1;
            }
            auto nextRes = dp(lo, quota - 1);
            
            vector<int> newSelected = nextRes.second;
            newSelected.push_back(origIdx);
            sort(newSelected.begin(), newSelected.end());
            pair<long long, vector<int>> pick = {(long long)w + nextRes.first, newSelected};
            
            bool pickBetter = pick.first > skip.first || 
                               (pick.first == skip.first && pick.second < skip.second);
            
            return memo[i][quota] = pickBetter ? pick : skip;
        };
        
        return dp(0, 4).second;
    }
};