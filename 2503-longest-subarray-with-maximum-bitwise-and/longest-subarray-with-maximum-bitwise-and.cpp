class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxEle = *max_element(nums.begin(), nums.end());

        int i = 0;
        int cnt = 0;
        int maxi = -1;
        while(i < nums.size()) {
            if(nums[i] == maxEle) {
                while(i < nums.size() && nums[i++] == maxEle) cnt++;
                maxi = max(maxi, cnt);
                cnt = 0;
            }
            else i++;
        }
        return maxi;
    }
};