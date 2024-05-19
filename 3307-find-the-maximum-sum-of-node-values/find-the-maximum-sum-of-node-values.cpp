class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        long long sum = 0;
        int cnt = 0;
        int mini = INT_MAX;

        for(auto it : nums) {
            if((it ^ k) > it) {
                sum += it ^ k;
                mini = min(mini, (it ^ k) - it);
                cnt++;
            }
            else {
                sum += it;
                mini = min(mini, it - (it ^ k));
            }
        }
        if(cnt % 2 == 0) return sum;
        return sum - mini;
    }
};