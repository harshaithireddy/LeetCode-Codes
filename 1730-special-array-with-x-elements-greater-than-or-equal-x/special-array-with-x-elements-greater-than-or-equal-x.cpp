class Solution {
public:
    int count(vector<int>& nums, int t) {
        int res = 0;
        for(auto it : nums) {
            if(it >= t) res++;
        }
        return res;
    }
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int left = 0;
        int right = nums.size();

        while(left <= right) {
            int mid = (left + right) / 2;

            int res = count(nums, mid);
            if(res == mid) return mid;
            else if(res > mid) left = mid + 1;
            else right = mid - 1;
        }
        return -1;
    }
};