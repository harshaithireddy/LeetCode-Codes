auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long n = nums.size(), sum = 0, maxi = 0;
        unordered_map<int, int> mpp;

        for(int i = 0; i < n; i++) {
            mpp[nums[i]]++;
            sum += nums[i];

            if(i >= k) {
                int x = nums[i - k];
                mpp[x]--;
                sum -= x;
                if(mpp[x] == 0) {
                    mpp.erase(x);
                }
            }

            if(i >= k - 1 && mpp.size() == k) {
                maxi = max(maxi, sum);
            }
        }

        return maxi;
    }
};