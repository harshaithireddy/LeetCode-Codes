auto speedUp = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c++';
}();

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> pq(nums.begin(), nums.end());
        int cnt = 0;

        while(pq.size() > 1) {
            long long x = pq.top();
            pq.pop();

            if(x >= k) break;

            long long y = pq.top();
            pq.pop();

            pq.push(x * 2 + y);
            cnt++;
        }
        return cnt;
    }
};
