class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return 1;

        int dec = 1, inc = 1;
        int res = 0;
        for(int i = 1; i < n; i++) {
            if(nums[i] > nums[i-1]) {
                inc++;
                dec = 1;
            }
            else if(nums[i] < nums[i-1]) {
                dec++;
                inc = 1;
            }
            else {
                dec = 1;
                inc = 1;
            }
            res = max({res, inc, dec});
        }
        return res;
    }
};