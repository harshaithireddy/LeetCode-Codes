class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n, 1);
        vector<int> suff(n, 1);

        for(int i = 1; i < n; i++) {
            if(nums[i] > nums[i-1]) pre[i] = pre[i-1] + 1;
        }

        for(int i = n - 2; i >= 0; i--) {
            if(nums[i] < nums[i+1]) suff[i] = suff[i+1] + 1;
        }

        int res = 0;
        for(int i = 0; i < n - 1; i++) {
            if(pre[i] >= 1 && suff[i + 1] >= 1) {
                res = max(res, min(pre[i], suff[i + 1]));
            }
        }
        return res;
    }
};
