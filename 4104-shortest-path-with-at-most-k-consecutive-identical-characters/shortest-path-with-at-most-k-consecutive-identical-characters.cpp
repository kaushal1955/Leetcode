
class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges,
                     string labels, int k) {

        // Step 1: Build adjacency list
        vector<vector<pair<int, int>>> adj(n);

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];

            adj[u].push_back({v, w});
        }

        // Step 2: Distance array
        // dist[node][consecutive_count]
        const long long INF = 1e18;

        vector<vector<long long>> dist(
            n, vector<long long>(k + 1, INF)
        );

        // Step 3: Min heap
        // {distance, node, consecutive_count}
        using State = tuple<long long, int, int>;

        priority_queue<
            State,
            vector<State>,
            greater<State>
        > pq;

        // Step 4: Initial state
        dist[0][1] = 0;
        pq.push({0, 0, 1});

        // Step 5: Dijkstra
        while (!pq.empty()) {

            auto [d, u, cnt] = pq.top();
            pq.pop();

            // Ignore outdated states
            if (d != dist[u][cnt]) {
                continue;
            }

            // Destination reached
            if (u == n - 1) {
                return (int)d;
            }

            // Explore neighbors
            for (auto &[v, wt] : adj[u]) {

                int newCount;

                if (labels[u] == labels[v]) {
                    newCount = cnt + 1;
                }
                else {
                    newCount = 1;
                }

                // Check constraint
                if (newCount > k) {
                    continue;
                }

                long long newDist = d + wt;

                // Relaxation
                if (newDist < dist[v][newCount]) {

                    dist[v][newCount] = newDist;

                    pq.push({
                        newDist,
                        v,
                        newCount
                    });
                }
            }
        }

        // No valid path exists
        return -1;
    }
};
