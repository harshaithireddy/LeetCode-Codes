class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int m = land.size();
        int n = land[0].size();

        vector<vector<int>> res;

        for(int r1 = 0; r1 < m; r1++) {
            for(int c1 = 0; c1 < n; c1++) {
                if(land[r1][c1] == 1) {
                    int r2;
                    int c2;
                    for(r2 = r1; r2 < m && land[r2][c1] == 1; r2++) {
                        for(c2 = c1; c2 < n && land[r2][c2] == 1; c2++) {
                            land[r2][c2] = 0;
                        }
                    }
                    res.push_back({r1, c1, r2 - 1, c2 - 1});
                }
            }
        }
        return res;
    }
};