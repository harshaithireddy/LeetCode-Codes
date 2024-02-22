class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int res1 = nums[n-1] * nums[n-2] * nums[n-3];

        int res2 = 0;
        if(nums[0] < 0 && nums[1] < 0) {
            res2 = nums[0] * nums[1] * nums[n-1];
        }
        return max(res1, res2);
    }
};