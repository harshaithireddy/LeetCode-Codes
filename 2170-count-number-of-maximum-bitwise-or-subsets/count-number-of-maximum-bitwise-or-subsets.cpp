class Solution {
public:
    void fun(vector<int>& nums, int ind, int orr, int& cnt, int maxOr) {
        if(ind == nums.size()) {
            if(orr == maxOr) cnt++;
            return;
        }

        fun(nums, ind +1, orr | nums[ind], cnt, maxOr);

        fun(nums, ind + 1, orr, cnt, maxOr);
    }
    int countMaxOrSubsets(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        
        int maxOr = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            maxOr |= nums[i];
        }
        int cnt = 0;
        fun(nums, 0, 0, cnt, maxOr);

        return cnt;
    }
};