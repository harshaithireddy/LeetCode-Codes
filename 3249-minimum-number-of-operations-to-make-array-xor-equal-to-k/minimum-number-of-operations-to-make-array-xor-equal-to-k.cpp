class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int res = 0;
        for(int bit = 0; bit <= 20; bit++) {
            int xorVal = 0;
            for(auto it : nums) {
                int bitVal = (1 << bit) & it;
                xorVal = xorVal ^ bitVal;
            }
            int kBitVal = (1 << bit) & k;
            if(kBitVal != xorVal) res++;
        }
        return res;
    }
};