class Solution {
public:
    int subArraysLessThanEqualToGoal(vector<int>& nums, int goal) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int i = 0;
        int j = 0;
        int cnt = 0;
        int res = 0;
        while(j < nums.size()) {
            if(nums[j] % 2 == 1) cnt++;
            while(i <= j && cnt > goal) {
                if(nums[i] % 2 == 1) cnt--;
                i++;
            }
            res += j - i + 1;
            j++;
        }
        return res;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return subArraysLessThanEqualToGoal(nums, k) - subArraysLessThanEqualToGoal(nums, k - 1);
    }

};