class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size();
        int m = tasks.size();
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> available;
        for (int i = 0; i < n; ++i) {
            available.push({servers[i], i});
        }
        
        priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int>>, greater<tuple<long long, int, int>>> busy;
        vector<int> ans(m);
        long long currentTime = 0;
        
        for (int j = 0; j < m; ++j) {
            currentTime = max(currentTime, (long long)j);
            
            if (available.empty() && !busy.empty()) {
                currentTime = max(currentTime, get<0>(busy.top()));
            }
            
            while (!busy.empty() && get<0>(busy.top()) <= currentTime) {
                auto [freeTime, weight, index] = busy.top();
                busy.pop();
                available.push({weight, index});
            }
            
            auto [weight, index] = available.top();
            available.pop();
            
            ans[j] = index;
            busy.push({currentTime + tasks[j], weight, index});
        }
        
        return ans;
    }
};