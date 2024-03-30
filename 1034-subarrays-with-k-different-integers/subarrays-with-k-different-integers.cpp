class Solution {
    int subarraysCount(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        int right = 0;
        int left = 0;
        int cnt = 0;
        while(right < nums.size()) {
            mpp[nums[right]]++;
            while(mpp.size() > k) {
                mpp[nums[left]]--;
                if(mpp[nums[left]] == 0) mpp.erase(nums[left]);
                left++;
            }
            cnt += right - left + 1;
            right++;
        }
        return cnt;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int x = subarraysCount(nums, k);
        int y = subarraysCount(nums, k - 1);

        return x - y;
    }
};