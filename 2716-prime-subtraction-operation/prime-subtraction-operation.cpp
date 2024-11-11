class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        vector<bool> Prime(1001, true);
        Prime[0] = Prime[1] = false;
        
        for(int i = 2; i * i <= 1000; i++) {
            if(Prime[i]) {
                for(int j = i * i; j <= 1000; j += i) {
                    Prime[j] = false;
                }
            }
        }

        int prev = 0;
        for(int i = 0; i < nums.size(); i++) {
            bool flag = false;
            for(int j = nums[i] - 1; j >= 2; j--) {
                if(Prime[j] && nums[i] - j > prev) {
                    nums[i] -= j;
                    prev = nums[i];
                    flag = true;
                    break;
                }
            }
            
            if(!flag && nums[i] <= prev) {
                return false;
            }
            prev = nums[i];
        }
        
        return true;
    }
};