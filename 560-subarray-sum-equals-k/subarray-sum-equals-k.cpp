class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        int sum = 0;
        int res = 0;
        mpp[sum] = 1;

        for(auto it : nums) {
            sum += it;
            if(mpp.find(sum - k) != mpp.end()){
                res += mpp[sum - k];
            }
            mpp[sum]++;
        }
        return res;
    }
};