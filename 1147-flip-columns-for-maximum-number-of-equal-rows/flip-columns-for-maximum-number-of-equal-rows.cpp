class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string, int> mpp;
        int res = 0;

        for(int i = 0; i < matrix.size(); i++) {
            string x = "";
            for(int j = 0; j < matrix[i].size(); j++) {
                x += matrix[i][j] == 0 ? '0' : '1';
            }

            if(x[0] == '1') {
                for(int j = 0; j < matrix[i].size(); j++) {
                    x[j] = matrix[i][j] == 0 ? '1' : '0';
                }
            }

            mpp[x]++;
            res = max(res, mpp[x]);
        }
        return res;
    }
};
