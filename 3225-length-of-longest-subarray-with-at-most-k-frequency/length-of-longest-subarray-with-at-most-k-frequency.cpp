class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        unordered_map<int, int> mpp;
        int maxi = 0;
        int i = 0;
        int j = 0;

        while(j < nums.size()) {
            mpp[nums[j]]++;
            while(i <= j && mpp[nums[j]] > k) {
                mpp[nums[i]]--;
                i++;
            }
            maxi = max(maxi, j - i + 1);
            j++;
        }
        return maxi;
    }
};