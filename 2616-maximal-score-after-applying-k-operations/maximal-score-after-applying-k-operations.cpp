class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        
        priority_queue<int> pq;
        for(int i = 0; i < nums.size(); i++) pq.push(nums[i]);

        long long res = 0;
        while(k--) {
            int x = pq.top();
            pq.pop();

            res += x;
            if(x % 3 == 0) {
                pq.push(x / 3);
            }
            else pq.push(ceil(x / 3.0));
        }
        return res;
    }
};