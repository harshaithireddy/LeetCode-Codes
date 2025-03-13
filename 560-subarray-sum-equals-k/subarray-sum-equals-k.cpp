class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        int sum = 0;
        int res = 0;
        mpp[sum] = 1;

        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if(mpp.find(sum - k) != mpp.end()){
                res += mpp[sum - k];
            }
            mpp[sum]++;
        }
        return res;
    }
};