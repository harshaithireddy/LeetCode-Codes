class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        auto helper = [&](int dist) {
            int l = 0;
            int res = 0;
            for(int r = 0; r < nums.size(); r++) {
                while(nums[r] - nums[l] > dist) {
                    l += 1;
                }
                res += r - l;
            }
            return res;
        };

        int l = 0;
        int r = nums.back();

        while(l < r) {
            int m = l + (r - l) / 2;
            int pairs = helper(m);

            if(pairs >= k) r = m;
            else l = m + 1;
        }
        return r;
    }
};