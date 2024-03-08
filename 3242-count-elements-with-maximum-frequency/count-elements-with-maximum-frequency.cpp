class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int maxi = -1;
        unordered_map<int, int> mpp;
        for(auto it : nums) {
            mpp[it]++;
            maxi = max(maxi, mpp[it]);
        }
        int cnt = 0;
        for(auto it : mpp) {
            if(it.second == maxi) cnt++;
        }
        return cnt * maxi;
    }
};