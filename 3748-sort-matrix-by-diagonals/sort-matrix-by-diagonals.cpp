class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        for(int row = 0; row < n; row++) {
            int i = row;
            int j = 0;
            vector<int> diag;
            while(i < n && j < n) {
                diag.push_back(grid[i][j]);
                i++;
                j++;
            }

            sort(diag.begin(), diag.end(), greater<int>());

            i = row, j = 0;
            int ind = 0;
            while(i < n && j < n) {
                grid[i][j] = diag[ind++];
                i++;
                j++;
            }
        }

        for(int col = 1; col < n; col++) {
            int i = 0;
            int j = col;
            vector<int> diag;
            while(i < n && j < n) {
                diag.push_back(grid[i][j]);
                i++;
                j++;
            }

            sort(diag.begin(), diag.end());

            i = 0, j = col;
            int ind = 0;
            while(i < n && j < n) {
                grid[i][j] = diag[ind++];
                i++;
                j++;
            }
        }
        return grid;
    }
};