class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int x = 1 << (nums.size());

        vector<vector<int>> res;
        for(int i = 0; i < x; i++) {
            vector<int> V;
            for(int j = 0; j < nums.size(); j++) {
                if((i & (1 << j)) != 0) {
                    V.push_back(nums[j]);
                }
            }
            res.push_back(V);
        }
        return res;
    }
};