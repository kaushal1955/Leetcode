class Solution {
public:
    static const int MAXK = 5;
    int k, n;
    
    struct NodeData {
        long long M[MAXK][MAXK];
        long long fullProd;
    };
    
    vector<NodeData> tree;
    vector<int> numsArr;
    
    NodeData identityNode() {
        NodeData res{};
        for (int a = 0; a < k; a++)
            for (int c = 0; c < k; c++)
                res.M[a][c] = 0;
        res.fullProd = 1 % k;
        return res;
    }
    
    NodeData leafNode(long long val) {
        NodeData res{};
        for (int a = 0; a < k; a++)
            for (int c = 0; c < k; c++)
                res.M[a][c] = 0;
        long long v = val % k;
        for (int a = 0; a < k; a++) {
            int c = (int)((a * v) % k);
            res.M[a][c] = 1;
        }
        res.fullProd = v;
        return res;
    }
    
    NodeData mergeNodes(const NodeData& L, const NodeData& R) {
        NodeData res{};
        res.fullProd = (L.fullProd * R.fullProd) % k;
        for (int a = 0; a < k; a++) {
            int m = (int)((a * L.fullProd) % k);
            for (int c = 0; c < k; c++) {
                res.M[a][c] = L.M[a][c] + R.M[m][c];
            }
        }
        return res;
    }
    
    void build(int node, int l, int r) {
        if (l == r) { tree[node] = leafNode(numsArr[l]); return; }
        int mid = (l + r) / 2;
        build(2*node, l, mid);
        build(2*node+1, mid+1, r);
        tree[node] = mergeNodes(tree[2*node], tree[2*node+1]);
    }
    
    void update(int node, int l, int r, int idx, long long val) {
        if (l == r) { tree[node] = leafNode(val); return; }
        int mid = (l + r) / 2;
        if (idx <= mid) update(2*node, l, mid, idx, val);
        else update(2*node+1, mid+1, r, idx, val);
        tree[node] = mergeNodes(tree[2*node], tree[2*node+1]);
    }
    
    NodeData query(int node, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) return identityNode();
        if (ql <= l && r <= qr) return tree[node];
        int mid = (l + r) / 2;
        NodeData leftRes = query(2*node, l, mid, ql, qr);
        NodeData rightRes = query(2*node+1, mid+1, r, ql, qr);
        return mergeNodes(leftRes, rightRes);
    }
    
    vector<int> resultArray(vector<int>& nums, int k_, vector<vector<int>>& queries) {
        k = k_;
        n = nums.size();
        numsArr = nums;
        tree.assign(4 * n, NodeData{});
        build(1, 0, n - 1);
        
        vector<int> result;
        result.reserve(queries.size());
        int startRem = 1 % k;
        
        for (auto& q : queries) {
            int index = q[0], value = q[1], start = q[2], x = q[3];
            update(1, 0, n - 1, index, value);
            NodeData res = query(1, 0, n - 1, start, n - 1);
            result.push_back((int)res.M[startRem][x]);
        }
        
        return result;
    }
};