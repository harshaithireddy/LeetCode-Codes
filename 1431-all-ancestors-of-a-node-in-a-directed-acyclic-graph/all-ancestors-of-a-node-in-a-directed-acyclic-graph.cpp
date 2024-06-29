class Solution {
public:
    void dfs(int i, vector<vector<int>>& V, vector<bool>& vis) {
        vis[i] = true;
        for(int x = 0; x < V[i].size(); x++) {
            if(vis[V[i][x]]) continue;
            dfs(V[i][x], V, vis);
        }
    }

    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> res(n);
        vector<vector<int>> V(n);
        for(int i = 0; i < edges.size(); i++) {
            V[edges[i][0]].push_back(edges[i][1]);
        }

        for(int i = 0; i < n; i++) {
            vector<bool> vis(n, false);
            dfs(i, V, vis);
            for(int j = 0; j < n; j++) {
                if(i == j) continue;
                if(vis[j] == true) res[j].push_back(i);
            }
        }
        return res;
    }
};