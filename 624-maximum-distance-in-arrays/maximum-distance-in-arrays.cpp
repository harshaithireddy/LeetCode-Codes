class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int currMini = arrays[0][0];
        int currMaxi = arrays[0].back();
        int res = 0;
        for(int i = 1; i < arrays.size(); i++) {
            res = max(res, max((arrays[i].back() - currMini), (currMaxi - arrays[i][0])));

            currMini = min(currMini, arrays[i][0]);
            currMaxi = max(currMaxi, arrays[i].back());
        }
        return res;
    }
};