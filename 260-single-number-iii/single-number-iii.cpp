class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        long long xorr = 0;
        for(int i = 0; i < nums.size(); i++) {
            xorr = nums[i] ^ xorr;
        }

        int rightMost = (xorr & -xorr);

        int b1 = 0, b2 = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] & rightMost) b1 = b1 ^ nums[i];
            else b2 = b2 ^ nums[i];
        }
        return {b1, b2};
    }
};