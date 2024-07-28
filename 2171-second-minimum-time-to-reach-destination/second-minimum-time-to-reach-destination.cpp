class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        unordered_map<int, vector<int>> mpp;
        vector<pair<int, int>> V(n + 1, {0, 0});
        queue<pair<int, int>> q;
        for(auto& e : edges) {
            mpp[e[0]].push_back(e[1]);
            mpp[e[1]].push_back(e[0]);
        }

        q.push({1,0});
        V[1] = {1, 0};

        while(true) {
            auto [node, arrive] = q.front();
            q.pop();
            bool needWait = (arrive / change) & 1;

            int waitTime = needWait ? ((arrive / change) + 1) * change - arrive : 0;
            int nextTime = arrive + waitTime + time;

            for(auto& nxt : mpp[node]) {
                if(V[nxt].first < 2 and V[nxt].second != nextTime) {
                    q.push({nxt, arrive + waitTime + time});
                    V[nxt].first += 1;
                    V[nxt].second = nextTime;
                    if(nxt == n and V[nxt].first == 2) {
                        return nextTime;
                    }
                }
            }
        }
        return -1;
    }
};