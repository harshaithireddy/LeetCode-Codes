class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            mpp[nums[i]]++;
        }

        int res = 0;
        for(auto it : mpp) {
            if(k == 0) {
                if(it.second > 1) res++;
            }
            else {
                if(mpp.find(it.first + k) != mpp.end()) res++;
            }
        }
        return res;
    }
};