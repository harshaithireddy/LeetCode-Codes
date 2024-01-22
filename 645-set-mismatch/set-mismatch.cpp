class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int duplicate, missing;

        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] == nums[i - 1]) {
                duplicate = nums[i];
                break;
            }
        }

        long long sum = accumulate(nums.begin(), nums.end(), 0) - duplicate;

        int n = nums.size();
        long long originalSum = (n * (n + 1)) / 2;

        missing = originalSum - sum;

        return {duplicate, missing};
    }
};