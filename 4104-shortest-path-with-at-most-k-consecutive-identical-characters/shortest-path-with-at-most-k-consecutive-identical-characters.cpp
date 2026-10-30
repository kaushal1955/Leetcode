class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adj[u].push_back({v, w});
        }
        
        priority_queue<
            tuple<long long, int, int>, 
            vector<tuple<long long, int, int>>, 
            greater<tuple<long long, int, int>>
        > pq;
        
        vector<vector<long long>> minCost(n, vector<long long>(k + 1, 1e18));
        
        pq.push({0, 0, 1});
        minCost[0][1] = 0;
        
        while (!pq.empty()) {
            auto [currentCost, u, count] = pq.top();
            pq.pop();
            
            if (u == n - 1) {
                return currentCost;
            }
            
            if (currentCost > minCost[u][count]) {
                continue;
            }
            
            for (auto& [v, weight] : adj[u]) {
                int nextCount;
                if (labels[v] == labels[u]) {
                    nextCount = count + 1;
                } else {
                    nextCount = 1;
                }
                
                if (nextCount <= k) {
                    long long newCost = currentCost + weight;
                    if (newCost < minCost[v][nextCount]) {
                        minCost[v][nextCount] = newCost;
                        pq.push({newCost, v, nextCount});
                    }
                }
            }
        }
        
        return -1;
    }
};