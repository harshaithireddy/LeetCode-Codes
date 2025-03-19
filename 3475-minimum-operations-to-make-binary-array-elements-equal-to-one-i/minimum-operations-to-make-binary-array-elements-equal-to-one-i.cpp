class Solution {
public:
    void flip(vector<int>& nums, int i) {
        nums[i] == 1 ? nums[i] = 0 : nums[i] = 1;
    }
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int res = 0;

        for(int i = 0; i < n - 2; i++) {
            if(nums[i] == 0) {
                flip(nums, i);
                flip(nums, i + 1);
                flip(nums, i + 2);

                res++;
            }
        }

        if(nums[n-1] == 0 || nums[n-2] == 0) return -1;
        return res;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();