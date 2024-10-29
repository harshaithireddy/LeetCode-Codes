auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> V(n, vector<int>(m));

        int res = 0;
        for(int j = m - 2; j >= 0; j--) {
            for(int i = 0; i < n; i++) {
                if(grid[i][j] < grid[i][j + 1]) {
                    V[i][j] = max(V[i][j], V[i][j + 1] + 1);
                }
                if(i > 0) {
                    if(grid[i-1][j+1] > grid[i][j]) {
                        V[i][j] = max(V[i][j], V[i-1][j+1] + 1);
                    }
                }
                if(i < grid.size() - 1) {
                    if(grid[i + 1][j + 1] > grid[i][j]) {
                        V[i][j] = max(V[i][j], V[i+1][j+1]+1);
                    }
                }
                if(j == 0) res = max(res, V[i][j]);
            }
        }
        return res;
    }
};