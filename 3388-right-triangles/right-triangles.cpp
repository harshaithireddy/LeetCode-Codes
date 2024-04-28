class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = grid.size();
        int m = grid[0].size();
        vector<int> rowCnt(n, 0), colCnt(m, 0);

        for(int i = 0; i < n; i++) {
            int cnt = 0;
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) cnt++;
            }
            rowCnt[i] = cnt;
        }

        for(int j = 0; j < m; j++) {
            int cnt = 0;
            for(int i = 0; i < n; i++) {
                if(grid[i][j] == 1) cnt++;
            }
            colCnt[j] = cnt;
        }

        long long res = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) res += ((rowCnt[i] - 1) * (colCnt[j] - 1));
            }
        }
        return res;
    }
};