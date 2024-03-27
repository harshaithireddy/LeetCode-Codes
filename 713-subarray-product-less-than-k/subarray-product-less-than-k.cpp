class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        if(k <= 1) return 0;
        int start = 0;
        int end = 0;
        int prod = 1;

        int cnt = 0;
        
        while(end < nums.size()) {
            prod *= nums[end];
            while(start < nums.size() && prod >= k) {
                prod /= nums[start];
                start++;
            }
            cnt += end - start + 1;
            end++;
        }
        return cnt;
    }
};