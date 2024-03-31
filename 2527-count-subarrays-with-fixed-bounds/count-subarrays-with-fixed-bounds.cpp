class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        ios_base::sync_with_stdio(false);
        long long res = 0;
        int minI = -1;
        int maxI = -1;
        int badI = -1;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == minK) minI = i;
            if(nums[i] == maxK) maxI = i;
            if(nums[i] < minK || nums[i] > maxK) badI = i;

            res += max(0, (min(minI, maxI) - badI));
        }
        return res;
    }
};