class Solution {
private:
    int countSetBits(int num) {
        int count = 0;
        while(num) {
            count += num & 1;
            num >>= 1;
        }
        return count;
    }
public:
    bool canSortArray(vector<int>& nums) {
        int currMin = nums[0], currMax = nums[0];
        int prevMax = INT_MIN;

        for(int i = 0; i < nums.size(); i++) {
            if(countSetBits(nums[i]) == countSetBits(currMin)) {
                currMin = min(currMin, nums[i]);
                currMax = max(currMax, nums[i]);
            }
            else {
                if(currMin < prevMax) return false;
                prevMax = currMax;
                currMin = nums[i];
                currMax = nums[i];
            }
        }

        if(currMin < prevMax) return false;
        return true;
    }
};