class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long totalSum = 0;
        for(int i = 0; i < nums.size(); i++) {
            totalSum += nums[i];
        }

        int rem = totalSum % p;
        if(rem == 0) return 0;

        unordered_map<int, int> mpp;
        mpp[0] = -1;
        long long prefixSum = 0;
        int minLength = nums.size();

        for(int i = 0; i < nums.size(); i++) {
            prefixSum += nums[i];
            int currMod = prefixSum % p;
            int targetMod = (currMod - rem + p) % p;

            if(mpp.find(targetMod) != mpp.end()) {
                minLength = min(minLength, i - mpp[targetMod]);
            }
            mpp[currMod] = i;
        }

        if(minLength == nums.size()) return -1;
        return minLength;
    }
};