class Solution {
public:
    void dfs(int r, int c, vector<vector<bool>>& vis, vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        if(r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] == 0 || vis[r][c]) return;
        
        vis[r][c] = true;
        vector<pair<int, int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        
        for(auto dir : dirs) {
            int nr = r + dir.first;
            int nc = c + dir.second;
            dfs(nr, nc, vis, grid);
        }
    }

    int countIslands(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<bool>> vis(rows, vector<bool>(cols, false));
        int count = 0;
        
        for(int r = 0; r < rows; r++) {
            for(int c = 0; c < cols; c++) {
                if(grid[r][c] == 1 && !vis[r][c]) {
                    dfs(r, c, vis, grid);
                    count++;
                }
            }
        }
        return count;
    }

    int minDays(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int rows = grid.size();
        int cols = grid[0].size();

        if(countIslands(grid) != 1) return 0;

        for(int r = 0; r < rows; r++) {
            for(int c = 0; c < cols; c++) {
                if(grid[r][c] == 0) continue;
                
                grid[r][c] = 0;
                if(countIslands(grid) != 1) return 1;
                grid[r][c] = 1;
            }
        }
        return 2;
    }
};