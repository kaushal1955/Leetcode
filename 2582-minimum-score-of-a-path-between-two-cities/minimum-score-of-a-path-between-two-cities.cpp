class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> graph(n + 1); 
        for (auto& r : roads) {
            graph[r[0]].push_back({r[1], r[2]});
            graph[r[1]].push_back({r[0], r[2]});
        }

        vector<bool> visited(n + 1, false);
        int ans = INT_MAX;

        stack<int> st;
        st.push(1);
        visited[1] = true;

        while (!st.empty()) {
            int node = st.top();
            st.pop();
            for (auto& [nei, w] : graph[node]) {
                ans = min(ans, w);
                if (!visited[nei]) {
                    visited[nei] = true;
                    st.push(nei);
                }
            }
        }

        return ans;
    }
};