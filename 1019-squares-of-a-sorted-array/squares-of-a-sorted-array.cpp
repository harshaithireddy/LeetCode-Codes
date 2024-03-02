class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> res(nums.size());
        for(int i = 0; i < nums.size(); i++) {
            nums[i] = nums[i] * nums[i];
        }
        // sort(res.begin(), res.end());
        int left = 0;
        int right = nums.size() - 1;
        int i = nums.size() - 1;
        while(left <= right) {
            if(nums[left] > nums[right]) {
                res[i] = nums[left];
                left++;
                i--;
            }
            else {
                res[i] = nums[right];
                right--;
                i--;
            }
        }
        return res;
    }
};