class Solution {
    vector<vector<int>> adj;
    vector<int> parent, depth, sz, heavy, head, pos;
    vector<int> seg;
    int timer = 0;

    int getMask(char c) {
        return 1 << (c - 'a');
    }

    void buildSegmentTree(int node, int l, int r,
                          const vector<int>& arr) {
        if (l == r) {
            seg[node] = arr[l];
            return;
        }

        int mid = (l + r) / 2;
        buildSegmentTree(node * 2, l, mid, arr);
        buildSegmentTree(node * 2 + 1, mid + 1, r, arr);

        seg[node] = seg[node * 2] ^ seg[node * 2 + 1];
    }

    void update(int node, int l, int r, int idx, int val) {
        if (l == r) {
            seg[node] = val;
            return;
        }

        int mid = (l + r) / 2;

        if (idx <= mid)
            update(node * 2, l, mid, idx, val);
        else
            update(node * 2 + 1, mid + 1, r, idx, val);

        seg[node] = seg[node * 2] ^ seg[node * 2 + 1];
    }

    int query(int node, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr)
            return seg[node];

        int mid = (l + r) / 2;
        int ans = 0;

        if (ql <= mid)
            ans ^= query(node * 2, l, mid, ql, qr);

        if (qr > mid)
            ans ^= query(node * 2 + 1, mid + 1, r, ql, qr);

        return ans;
    }

    int pathQuery(int u, int v, int n) {
        int mask = 0;

        while (head[u] != head[v]) {
            if (depth[head[u]] < depth[head[v]])
                swap(u, v);

            mask ^= query(1, 0, n - 1, pos[head[u]], pos[u]);
            u = parent[head[u]];
        }

        if (depth[u] > depth[v])
            swap(u, v);

        mask ^= query(1, 0, n - 1, pos[u], pos[v]);
        return mask;
    }

public:
    vector<bool> palindromePath(
        int n,
        vector<vector<int>>& edges,
        string s,
        vector<string>& queries
    ) {
        adj.assign(n, {});

        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        parent.assign(n, -1);
        depth.assign(n, 0);
        sz.assign(n, 1);
        heavy.assign(n, -1);
        head.assign(n, 0);
        pos.assign(n, 0);

        vector<int> order;
        order.reserve(n);
        order.push_back(0);
        parent[0] = 0;

        for (int i = 0; i < (int)order.size(); i++) {
            int u = order[i];

            for (int v : adj[u]) {
                if (v == parent[u])
                    continue;

                parent[v] = u;
                depth[v] = depth[u] + 1;
                order.push_back(v);
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            int u = order[i];
            int largest = 0;

            for (int v : adj[u]) {
                if (parent[v] != u)
                    continue;

                sz[u] += sz[v];

                if (sz[v] > largest) {
                    largest = sz[v];
                    heavy[u] = v;
                }
            }
        }

        vector<pair<int, int>> st;
        st.push_back({0, 0});
        timer = 0;

        while (!st.empty()) {
            auto [start, chainHead] = st.back();
            st.pop_back();

            for (int u = start; u != -1; u = heavy[u]) {
                head[u] = chainHead;
                pos[u] = timer++;

                for (int v : adj[u]) {
                    if (parent[v] == u && v != heavy[u])
                        st.push_back({v, v});
                }
            }
        }

        vector<int> arr(n);

        for (int u = 0; u < n; u++)
            arr[pos[u]] = getMask(s[u]);

        seg.assign(4 * n, 0);
        buildSegmentTree(1, 0, n - 1, arr);

        vector<bool> ans;

        for (string& q : queries) {
            stringstream ss(q);
            string type;
            int u;
            ss >> type >> u;

            if (type == "update") {
                char c;
                ss >> c;

                s[u] = c;
                update(1, 0, n - 1, pos[u], getMask(c));
            } else {
                int v;
                ss >> v;

                int mask = pathQuery(u, v, n);
                ans.push_back((mask & (mask - 1)) == 0);
            }
        }

        return ans;
    }
};