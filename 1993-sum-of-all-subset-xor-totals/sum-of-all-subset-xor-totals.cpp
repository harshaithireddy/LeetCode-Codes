class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = nums.size();
        int sum = 0;

        for(int x = 0; x < pow(2, n); x++) {
            int xorSum = 0;
            for(int i = 0; i < n; i++) {
                if(x & (1 << i)) {
                    xorSum ^= nums[i];
                }
            }
            sum += xorSum;
        }
        return sum;
    }
};