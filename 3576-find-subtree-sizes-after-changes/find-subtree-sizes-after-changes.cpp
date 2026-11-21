
class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();

        
        vector<vector<int>> adj(n);

        for (int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }

        
        vector<int> newParent(n);
        vector<vector<int>> st(26);

        function<void(int)> dfs1 = [&](int u) {
            int c = s[u] - 'a';

            
            if (!st[c].empty()) {
                newParent[u] = st[c].back();
            } else {
                newParent[u] = parent[u];
            }

           
            st[c].push_back(u);

            
            for (int v : adj[u]) {
                dfs1(v);
            }

            
            st[c].pop_back();
        };

        dfs1(0);

 
        vector<vector<int>> newAdj(n);

        for (int i = 1; i < n; i++) {
            newAdj[newParent[i]].push_back(i);
        }

      
        vector<int> ans(n, 0);

        function<int(int)> dfs2 = [&](int u) {
            ans[u] = 1;

            for (int v : newAdj[u]) {
                ans[u] += dfs2(v);
            }

            return ans[u];
        };

        dfs2(0);

        return ans;
    }
};
