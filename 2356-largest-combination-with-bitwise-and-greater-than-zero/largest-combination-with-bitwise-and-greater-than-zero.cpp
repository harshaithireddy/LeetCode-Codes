auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.tie(nullptr);
    return 'c';
}();

class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int res = 0;
        for(int bit = 0; bit < 32; bit++) {
            int cnt = 0;
            for(int i = 0; i < candidates.size(); i++) {
                if(candidates[i] & (1 << bit)) cnt++;
            }
            res = max(res, cnt);
        }
        return res;
    }
};