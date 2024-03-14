class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        if(mat.empty()) return {};
        if(mat.size() == 1) return mat[0];
        
        int n = mat.size();
        int m = mat[0].size();

        vector<int> res(n * m);

        int row = 0;
        int col = 0;
        int i = 0;

        bool up = true;

        while(i < n * m) {
            if(up == true) {
                while(row >= 0 && col < m) {
                    res[i++] = mat[row][col];
                    if(col == m - 1) {
                        row++;
                        break;
                    }
                    if(row == 0) {
                        col++;
                        break;
                    }
                    row--;
                    col++;
                }
            }
            else {
                while(col >= 0 && row < n) {
                    res[i++] = mat[row][col];
                    if(row == n - 1) {
                        col++;
                        break;
                    }
                    if(col == 0) {
                        row++;
                        break;
                    }
                    row++;
                    col--;
                }
            }
            up = !up;
        }
        return res;
    }
};