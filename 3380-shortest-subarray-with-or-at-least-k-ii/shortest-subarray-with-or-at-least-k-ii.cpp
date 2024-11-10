class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> bits(32, 0);

        int currOR = 0;
        int l = 0;
        int res = INT_MAX;
        
        for(int r = 0; r < n; r++) {
            currOR |= nums[r];
            
            for(int bit = 0; bit < 32; bit++) {
                if(nums[r] & (1 << bit)) {
                    bits[bit]++;
                }
            }
            
            while(l <= r && currOR >= k) {
                res = min(res, r - l + 1);
                
                int updatedOR = 0;
                for(int bit = 0; bit < 32; bit++) {
                    if(nums[l] & (1 << bit)) {
                        bits[bit]--;
                    }
                    if(bits[bit] > 0) {
                        updatedOR |= (1 << bit);
                    }
                }
                currOR = updatedOR;
                l++;
            }
        }
        
        return res == INT_MAX ? -1 : res;
    }
};