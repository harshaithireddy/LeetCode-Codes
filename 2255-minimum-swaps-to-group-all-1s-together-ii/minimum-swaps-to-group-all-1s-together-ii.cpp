class Solution {
public:
    int minSwaps(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    
        int totalOnes = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++) if(nums[i] == 1) totalOnes++;

        int l = 0;
        int window = 0;
        int maxWindow = 0;
        for(int r = 0; r < 2 * n; r++) {
            if(nums[r % n] == 1) window++;

            if(r - l + 1 > totalOnes) {
                window -= nums[l % n];
                l += 1;
            }
            maxWindow = max(maxWindow, window);
        }
        return totalOnes - maxWindow;
    }
};