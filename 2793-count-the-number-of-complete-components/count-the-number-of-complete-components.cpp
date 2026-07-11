class Solution {
public:
    vector<vector<int>> graph;
    vector<bool> vis;

    void dfs(int node, int &vertices, int &edges) {
        vis[node] = true;
        vertices++;
        edges += graph[node].size();

        for (int nei : graph[node]) {
            if (!vis[nei])
                dfs(nei, vertices, edges);
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        graph.resize(n);
        vis.assign(n, false);

        for (auto &e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                int vertices = 0;
                int edgeCount = 0;

                dfs(i, vertices, edgeCount);

                edgeCount /= 2;   // each edge counted twice

                if (edgeCount == vertices * (vertices - 1) / 2)
                    ans++;
            }
        }

        return ans;
    }
};