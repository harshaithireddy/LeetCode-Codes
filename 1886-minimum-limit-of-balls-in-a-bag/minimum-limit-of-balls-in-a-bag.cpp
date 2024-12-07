class Solution {
public:
    bool isPossible(vector<int>& nums, int mid, int maxOperations) {
        int total = 0;
        for(int num : nums) {
            total += (num - 1) / mid;
            if(total > maxOperations) return false;
        }
        return true;
    }

    int minimumSize(vector<int>& nums, int maxOperations) {
        int l = 1;
        int r = *max_element(nums.begin(), nums.end());
        int res = r;

        while(l <= r) {
            int mid = l + (r - l) / 2;
            if(isPossible(nums, mid, maxOperations)) {
                res = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return res;
    }
};