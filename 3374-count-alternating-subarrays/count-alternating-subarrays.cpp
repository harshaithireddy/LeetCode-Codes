class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        long long res = 0;
        int lastOccurance = -1;
        for(int i = 0; i < nums.size(); i++) {
            if(i > 0 && nums[i] == nums[i-1]) lastOccurance = i - 1;
            res += i - lastOccurance;
        }
        return res;
    }
};