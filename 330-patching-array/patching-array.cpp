class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int i = 0;
        long long sum = 0;
        int cnt = 0;

        int size = nums.size();

        while(sum < n) {
            if(i < size && sum + 1 >= nums[i]) {
                sum += nums[i];
                i++;
            }
            else {
                cnt++;
                sum += (sum + 1);
            }
        }
        return cnt;
    }
};