class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int rows = points.size();
        int cols = points[0].size();

        vector<long long> row(cols);
        for (int c = 0; c < cols; c++) {
            row[c] = points[0][c];
        }

        for (int r = 1; r < rows; r++) {
            vector<long long> nextRow(cols);
            vector<long long> left(cols, 0);
            vector<long long> right(cols, 0);

            left[0] = row[0];
            for (int c = 1; c < cols; c++) {
                left[c] = max(left[c - 1] - 1, row[c]);
            }

            right[cols - 1] = row[cols - 1];
            for (int c = cols - 2; c >= 0; c--) {
                right[c] = max(right[c + 1] - 1, row[c]);
            }

            for (int c = 0; c < cols; c++) {
                nextRow[c] = points[r][c] + max(left[c], right[c]);
            }

            row = nextRow;
        }

        return *max_element(row.begin(), row.end());
    }
};