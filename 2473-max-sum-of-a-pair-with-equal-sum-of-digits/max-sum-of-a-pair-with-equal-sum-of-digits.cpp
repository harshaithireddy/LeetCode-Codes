class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int maxi = -1;
        unordered_map<int, int> mpp;

        for(int i = 0; i < nums.size(); i++) {
            int n = nums[i];
            int temp = 0;
            while(n > 0) {
                temp += n % 10;
                n /= 10;
            }
            if(mpp.find(temp) != mpp.end()) maxi = max(maxi, mpp[temp] + nums[i]);

            mpp[temp] = max(mpp[temp], nums[i]);
        }
        return maxi;
    }
};