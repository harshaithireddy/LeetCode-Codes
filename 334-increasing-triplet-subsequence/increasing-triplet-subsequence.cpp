class Solution {
public:
    int speedup = []{ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0;}();
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();

        if(n < 3) return false;

        vector<int> minArr(n);
        vector<int> maxArr(n);

        minArr[0] = nums[0];
        for(int i = 1; i < n; i++) {
            minArr[i] = min(minArr[i-1], nums[i]);
        }

        maxArr[n-1] = nums[n-1];
        for(int i = n-2; i >= 0; i--) {
            maxArr[i] = max(maxArr[i+1], nums[i]);
        }

        for(int i = 1; i < n; i++) {
            if(minArr[i] < nums[i] && maxArr[i] > nums[i]) {
                return true;
            }
        }
        return false;
    }
};