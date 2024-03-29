class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        int maxi = 1;
        for(int i = 0; i < nums.size(); i++) {
            maxi = max(maxi, nums[i]);
        }

        int left = 0;
        int cnt = 0;
        long long res = 0;
        for(int right = 0; right < nums.size(); right++) {
            if(nums[right] == maxi) cnt++;

            while(cnt > k || (cnt == k && nums[left] != maxi)) {
                if(nums[left] == maxi) cnt--;
                left++;
            }
            if(cnt == k) res += (left + 1); 
        } 
        return res;
    }
};