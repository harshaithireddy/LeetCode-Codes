class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mpp;

        if(n == 1) return 0;
        for(int i = 0; i < n; i++) {
            mpp[nums[i]]++;
        }

        if(mpp.size() == 1) return 0;
        int maxi = 0;
        for(auto it : mpp) {
            if(mpp.find(it.first - 1) != mpp.end()) {
                maxi = max(maxi, it.second + mpp[it.first - 1]);
            }
        }
        return maxi;
    }
};