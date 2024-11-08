class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int xorr = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            xorr ^= nums[i];
        }

        vector<int> res(n);
        int x = (1 << maximumBit) - 1;
        for(int i = 0; i < n; i++) {
            res[i] = xorr ^ x;
            xorr ^= nums[n - i - 1]; 
        }
        return res;
    }
};