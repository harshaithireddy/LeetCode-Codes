class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        vector<int> V(right + 1, 0);
        for(auto it : ranges) {
            for(int i = it[0]; i <= it[1]; i++) {
                if(i <= right) V[i] = 1;
            }
        }
        bool flag = true;
        for(int i = left; i <= right; i++) {
            if(V[i] == 0) flag = false;
        }
        return flag;
    }
};