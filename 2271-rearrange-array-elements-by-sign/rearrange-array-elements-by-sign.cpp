class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> pos, neg;
        
        for(int i = 0; i < n; i++) {
            if(nums[i] > 0) {
                pos.push_back(nums[i]);
            }
            else {
                neg.push_back(nums[i]);
            }
        }

        for(int i = 0; i < n/2; i++) {
            nums[2 * i] = pos[i];
            nums[2 * i+1] = neg[i];
        }
        return nums;
    }
};