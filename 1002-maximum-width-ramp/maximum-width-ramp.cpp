auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();

        vector<int> maxi(n);
        maxi[n-1] = nums[n-1];
        for(int i = n-2; i >= 0; i--) {
            if(nums[i] >= maxi[i+1]) maxi[i] = nums[i];
            else maxi[i] = maxi[i+1];
        }

        int res = 0;
        int l = 0;
        for(int r = 0; r < n; r++) {
            while(nums[l] > maxi[r]) l++;
            res = max(res, r - l);
        }
        return res;
    }
};
