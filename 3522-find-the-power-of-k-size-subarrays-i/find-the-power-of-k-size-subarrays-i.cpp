class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int l = 0;
        int cnt = 1;
        vector<int> res;
        for(int r = 0; r < nums.size(); r++) {
            if(r > 0 && nums[r - 1] + 1 == nums[r]) {
                cnt++;
            }

            if(r - l + 1 > k) {
                if(nums[l] + 1 == nums[l + 1]) cnt--;
                l++;
            }
            
            if(r - l + 1 == k) {
                if(cnt == k) res.push_back(nums[r]);
                else res.push_back(-1);
            }
        }
        return res;
    }
};