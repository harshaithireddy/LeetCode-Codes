class Solution {
public:
    int dfs(vector<int>& nums, int i, int k, unordered_map<int, int>& mpp) {
        if(i == nums.size()) return 1;

        int pick = 0;
        if(!mpp[nums[i] - k] && !mpp[nums[i] + k]) {
            mpp[nums[i]]++;
            pick = dfs(nums, i + 1, k, mpp);
            mpp[nums[i]]--;
        }

        int notPick = dfs(nums, i + 1, k, mpp);

        return pick + notPick;
    }

    int beautifulSubsets(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        int res = dfs(nums, 0, k, mpp);

        return res - 1;
    }
};