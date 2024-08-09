class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();

        auto magic = [&](int r, int c) {
            // 1 - 9
            unordered_set<int> st;
            for(int i = r; i < r + 3; i++) {
                for(int j = c; j < c + 3; j++) {
                    if(st.find(grid[i][j]) != st.end() || grid[i][j] < 1 || grid[i][j] > 9) return 0;
                    st.insert(grid[i][j]);
                }
            }

            // rows
            for(int i = r; i < r + 3; i++) {
                int sum = grid[i][c] + grid[i][c + 1] + grid[i][c + 2];
                if(sum != 15) return 0;
            }

            // cols
            for(int i = c; i < c + 3; i++) {
                int sum = grid[r][i] + grid[r + 1][i] + grid[r + 2][i];
                if(sum != 15) return 0;
            }

            // diagonals
            if(grid[r][c] + grid[r + 1][c + 1] + grid[r + 2][c + 2] != 15 || 
                grid[r][c + 2] + grid[r + 1][c + 1] + grid[r + 2][c] != 15) return 0;

            return 1;
        };

        int res = 0;

        for(int r = 0; r < rows - 2; r++) {
            for(int c = 0; c < cols - 2; c++) {
                res += magic(r, c);
            }
        }
        return res;
    }
};