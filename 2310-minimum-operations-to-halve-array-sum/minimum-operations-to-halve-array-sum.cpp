class Solution {
public:
    int halveArray(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        
        double sum = accumulate(nums.begin(), nums.end(), 0.0);
        double half = sum / 2.0;

        priority_queue<double> pq(nums.begin(), nums.end());

        int cnt = 0;
        while(sum > half) {
            double x = pq.top();
            pq.pop();
            sum -= x / 2;

            pq.push(x / 2);
            cnt++;
        }

        return cnt;
    }
};
