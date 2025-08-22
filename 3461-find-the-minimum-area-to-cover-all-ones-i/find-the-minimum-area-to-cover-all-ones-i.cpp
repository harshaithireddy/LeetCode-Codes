class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int minX = INT_MAX;
        int maxX = -1;
        int minY = INT_MAX;
        int maxY = -1;

        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 1) {
                    minX = min(minX, i);
                    maxX = max(maxX, i);
                    minY = min(minY, j);
                    maxY = max(maxY, j);
                }
            }
        }
        return (maxX - minX + 1) * (maxY - minY + 1);
    }
};