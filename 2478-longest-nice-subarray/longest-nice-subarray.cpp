class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int x = 0;
        int l = 0;
        int res = 0;
        for(int r = 0; r < nums.size(); r++) {
            while(l < r && (x & nums[r]) != 0) {
                x ^= nums[l];
                l++;
            }
            res = max(res, r - l + 1);
            x |= nums[r];
        }
        return res;
    }
};
