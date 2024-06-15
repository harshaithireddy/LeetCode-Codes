class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int, int>> V;
        int n = profits.size();
        for(int i = 0; i < n; i++) V.push_back({capital[i], profits[i]});
        sort(V.begin(), V.end());

        priority_queue<int> pq;
        int res = w;
        int j = 0;
        for(int i = 0; i < k; i++) {
            while(j < n && V[j].first <= res) {
                pq.push(V[j].second);
                j++;
            }
            if(pq.size() == 0) return res;
            res += pq.top();
            pq.pop();
        }
        return res;
    }
};