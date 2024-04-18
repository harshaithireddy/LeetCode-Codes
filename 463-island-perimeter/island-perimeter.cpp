class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(false);
        int up, down, left, right, res = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 1) {
                    if(i == 0) up = 1;
                    else up = grid[i - 1][j] == 0;

                    if(j == 0) left = 1;
                    else left = grid[i][j - 1] == 0;

                    if(i == grid.size()-1) down = 1;
                    else down = grid[i + 1][j] == 0;

                    if(j == grid[0].size()-1) right = 1;
                    else right = grid[i][j + 1] == 0;

                    res += up + down + left + right;
                }
            }
        }
        return res;
    }
};