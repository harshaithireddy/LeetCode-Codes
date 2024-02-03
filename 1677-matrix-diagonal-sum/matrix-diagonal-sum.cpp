class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int res = 0;
        for(int i = 0; i < mat.size(); i++) {
            for(int j = 0; j < mat.size(); j++) {
                if(i == j) {
                    res += mat[i][j];
                    mat[i][j] = 0;
                }
                if(i + j == mat.size() - 1) {
                    res += mat[i][j];
                    mat[i][j] = 0;
                }
            }
        }
        return res;
    }
};