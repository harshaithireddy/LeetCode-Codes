class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<pair<int, int>> V;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == 0) {
                    V.push_back({i, j});
                }
            }
        }

        for(auto it : V) {
            int i = it.first;
            int j = it.second;
            for(int k = 0; k < m; k++) {
                matrix[k][j] = 0;
            }
            for(int k = 0; k < n; k++) {
                matrix[i][k] = 0;
            }
        }
    }
};
