class Solution {
public:
    void dfs(int node, vector<bool>& vis, vector<vector<int>>& grid) {
        if(vis[node] == true) return;
        vis[node] = true;

        for(auto it : grid[node]) {
            dfs(it, vis, grid);
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        ios_base::sync_with_stdio(false);
        vector<bool> vis(n, false);
        vector<vector<int>> grid(n);
        for(auto it : edges) {
            int u = it[0];
            int v = it[1];
            grid[u].push_back(v);
            grid[v].push_back(u);
        }
        dfs(source, vis, grid);
        return vis[destination];
    }
};