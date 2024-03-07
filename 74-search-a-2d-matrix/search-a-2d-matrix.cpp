class Solution {
public:
    bool binarySearch(vector<int>& arr, int target) {
        int i = 0;
        int j = arr.size() - 1;
        while(i <= j) {
            int m = i + (j - i) / 2;
            if(arr[m] == target) return true;
            if(arr[m] < target) i = m + 1;
            if(arr[m] > target) j = m - 1;
        }
        return false;
    }


    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        if(matrix[0][0] > target) return false;

        for(int i = 0; i < n; i++) {
            vector<int> x = matrix[i];
            if(matrix[i][0] <= target && matrix[i][m-1] >= target) {
                return binarySearch(x, target);
            }
        }
        return false;
    }
};