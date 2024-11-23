class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int rows = box.size();
        int cols = box[0].size();

        for(int r = 0; r < rows; r++) {
            int i = cols - 1;
            for(int c = cols - 1; c >= 0; c--) {
                if(box[r][c] == '#') {
                    swap(box[r][c], box[r][i]);
                    i--;
                }
                else if(box[r][c] == '*') i = c - 1;
            }
        }

        vector<vector<char>> res;
        for(int c = 0; c < cols; c++) {
            vector<char> x;
            for(int r = rows - 1; r >= 0; r--) {
                x.push_back(box[r][c]);
            }
            res.push_back(x);
        }
        return res;
    }
};