class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        ios_base::sync_with_stdio(false);
        unordered_map<int, int> mpp;
        int sum = 0;
        int cnt = 0;

        mpp[0] = 1;

        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if(mpp.find(sum - goal) != mpp.end()) {
                cnt += mpp[sum - goal];
            }
            mpp[sum]++;
        }
        return cnt;
    }
};