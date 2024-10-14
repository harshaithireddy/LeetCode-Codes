auto speedUp = []() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 'c++';
}();

class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);

        priority_queue<int> pq(piles.begin(), piles.end());

        while(k--) {
            int x = pq.top();
            pq.pop();
            pq.push(x - x / 2);
        }

        int res = 0;
        while(!pq.empty()) {
            res += pq.top();
            pq.pop();
        }
        return res;
    }
};