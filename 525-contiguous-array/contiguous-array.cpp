class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> mpp;
        int cnt = 0;
        int sum = 0;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 0) sum += -1;
            else sum += 1;

            if(sum == 0) cnt = max(cnt, i+1);
            else if(mpp.find(sum) != mpp.end()) {
                cnt = max(cnt, i - mpp[sum]);
            }
            else mpp[sum] = i;
        }
        return cnt;
    }
};