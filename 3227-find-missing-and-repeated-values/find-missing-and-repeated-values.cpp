class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> V(n * n + 1, 0);  
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                V[grid[i][j]]++;
            }
        }

        int missing = -1, repeated = -1;
        for(int i = 1; i < V.size(); i++) {
            if(V[i] == 0) missing = i;
            if(V[i] == 2) repeated = i;
        }
        
        return {repeated, missing};
    }
};
