class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int prefixSum = 0;
        unordered_map<int, int> mpp;
        mpp[0] = 0;
        for(int i = 0; i < n; i++) {
            prefixSum = (prefixSum + nums[i]) % k;
            if(mpp.find(prefixSum) != mpp.end()) {
                if(i + 1 - mpp[prefixSum] >= 2) return true;
            }
            else {
                mpp[prefixSum] = i + 1;
            }
        }
        return false;
    }
};