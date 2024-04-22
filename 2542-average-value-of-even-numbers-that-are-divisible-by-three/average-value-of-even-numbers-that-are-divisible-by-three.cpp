class Solution {
public:
    int averageValue(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        int sum = 0, cnt = 0;
        for(auto it : nums) {
            if(it % 6 == 0) {
                sum += it;
                cnt++;
            }
        }
        if(cnt == 0) return 0;
        return sum / cnt;
    }
};