class Solution {
public:
    vector<vector<char>> rotateMatrix(vector<vector<char>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();

    vector<vector<char>> transposed(n, vector<char>(m));
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            transposed[i][j] = matrix[j][i];
        }
    }

    for(int i = 0; i < n; ++i) {
        reverse(transposed[i].begin(), transposed[i].end());
    }
    return transposed;
}

    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        for(auto &it : box) {
            vector<char>& x = it;
            int i = x.size() - 1;
            int j = x.size() - 2;
            while(j >= 0) {
                if(x[j] == '*') {
                    j--;
                    i = j + 1;
                    continue;
                }
                if(x[i] == '.' && x[j] == '*' || x[i] == '*' && x[j] == '.') {
                    i--;
                    j--;
                }
                else if(x[i] == '.' && x[j] == '#') {
                    swap(x[i], x[j]);
                    i--;
                    j--;
                }
                else if(x[i] == '*' && x[j] == '#') {
                    i--;
                    j--;
                }
                else if(x[i] == '.' && x[j] == '.') {
                    j--;
                }
                else {
                    i--;
                    j--;
                }
            }
        }
        // for(auto it : box) {
        //     vector<char> x = it;
        //     for(auto i : x) cout << i << " ";
        // }
        // cout << endl;

        vector<vector<char>> res = rotateMatrix(box);
        return res;
    }
};