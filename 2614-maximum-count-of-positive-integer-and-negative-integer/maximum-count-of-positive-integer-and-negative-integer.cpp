class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        int s = 0, e = n - 1;
        int neg = -1, pos = -1;

        while(s <= e) {
            int m = (s + e) / 2;
            if(nums[m] < 0) {
                s = m + 1;
            }
            else {
                e = m - 1;
            }
        }
        neg = s;

        s = 0, e = n - 1;
        while(s <= e) {
            int m = (s + e) / 2;
            if(nums[m] > 0) {
                e = m - 1;
            }
            else {
                s = m + 1;
            }
        }
        pos = s;

        return max(neg, n - pos);
    }
};
