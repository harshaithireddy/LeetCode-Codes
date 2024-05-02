class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int res = -1;
        unordered_set<int> st(nums.begin(), nums.end());
        for(auto it : st) {
            if(st.find(-1 * it) != st.end()) {
                res = max(res, it);
            }
        }
        return res;
    }
};