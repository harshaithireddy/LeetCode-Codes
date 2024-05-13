class Solution {
public:
    void flipRow(vector<vector<int>>& grid, int i) {
        for(int x = 0; x < grid[0].size(); x++) {
            if(grid[i][x] == 0) grid[i][x] = 1;
            else grid[i][x] = 0;
        }
    }

    void flipCol(vector<vector<int>>& grid, int j) {
        for(int x = 0; x < grid.size(); x++) {
            if(grid[x][j] == 0) grid[x][j] = 1;
            else grid[x][j] = 0;
        }
    }

    int getVal(vector<int>& V) {
        int res = 0;
        for(auto it : V) {
            res = res * 2 + it;
        }
        return res;
    }
    int matrixScore(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        for(int i = 0; i < n; i++) {
            if(grid[i][0] == 0) flipRow(grid, i);
        }

        for(int j = 0; j < m; j++) {
            int ones = 0;
            for(int i = 0; i < n; i++) {
                if(grid[i][j] == 1) ones++; 
            }
            if(ones * 2 < n) flipCol(grid, j);
        }

        int res = 0;
        for(auto it : grid) {
            res += getVal(it);
        }
        return res;
    }
};
