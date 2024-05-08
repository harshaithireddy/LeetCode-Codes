class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<string> res(n);

        priority_queue<pair<int, int>> pq;
        for(int i = 0; i < n; i++) {
            pq.push({score[i], i});
        }
        
        vector<string> medal = {"Gold Medal", "Silver Medal", "Bronze Medal"};
        int i = 1;
        while(!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            int ind = top.second;
            if(i <= 3) res[ind] = medal[i - 1];
            else res[ind] = to_string(i);

            i++;
        }
        return res;
    }
};