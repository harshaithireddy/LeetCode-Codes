class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> V;
        for(int i = 0; i < numRows; i++) {
            if(i == 0) V.push_back({1});
            else if(i == 1) V.push_back({1, 1});
            else {
                vector<int> Back = V.back();
                vector<int> newRow;
                newRow.push_back(1);
                for(int j = 1; j < Back.size(); j++) {
                    newRow.push_back(Back[j - 1] + Back[j]);
                }
                newRow.push_back(1);
                V.push_back(newRow);
            }
        }
        return V;
    }
};