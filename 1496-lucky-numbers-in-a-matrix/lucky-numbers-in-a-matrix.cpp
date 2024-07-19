class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> res;
        
        unordered_set<int> st;
        for(int i = 0; i < m; i++) {
            int mini = matrix[i][0];
            for(int j = 1; j < n; j++) {
                mini = min(mini, matrix[i][j]);
            }
            st.insert(mini);
        }

        for(int i = 0; i < n; i++) {
            int maxi = matrix[0][i];
            for(int j = 1; j < m; j++) {
                maxi = max(maxi, matrix[j][i]);
            }
            if(st.find(maxi) != st.end()) res.push_back(maxi);
        }
        return res;
    }
};