class Solution {
public:
    int gold = 0;
    void traverse(int i, int j, int sum, vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        if(i < 0 || i >= row || j < 0 || j >= col || grid[i][j] == 0) return;

        int temp = grid[i][j];
        sum += grid[i][j];

        gold = max(gold, sum);
        grid[i][j] = 0;

        traverse(i+1, j, sum, grid);
        traverse(i-1, j, sum, grid);
        traverse(i, j+1, sum, grid);
        traverse(i, j-1, sum, grid);

        grid[i][j] = temp;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] != 0) traverse(i, j, 0, grid);
            }
        }
        return gold;
    }
};