class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        if(matrix[0][0] > target) return false;

        for(int i = 0; i < n; i++) {
            vector<int> x = matrix[i];
            if(matrix[i][0] <= target && matrix[i][m-1] >= target) {
                for(auto it : x) {
                    if(it == target) return true;
                }
            }
        }
        return false;
    }
};