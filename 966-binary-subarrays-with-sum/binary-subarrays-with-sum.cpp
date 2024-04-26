class Solution {
public:
    int binarySum(vector<int>& nums, int goal) {
        if(goal < 0) return 0;
        int r = 0;
        int l = 0;
        int sum = 0;
        int cnt = 0;
        while(r < nums.size()) {
            sum += nums[r];
            while(sum > goal) {
                sum -= nums[l];
                l++;
            }
            cnt += (r - l + 1);
            r++;
        }
        return cnt;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int a = binarySum(nums, goal);
        int b = binarySum(nums, goal - 1);

        return a - b;
    }
};