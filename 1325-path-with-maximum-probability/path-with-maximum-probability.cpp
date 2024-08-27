class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        vector<vector<pair<int, double>>> g(n);

        for(int i = 0; i < edges.size(); i++) {
            g[edges[i][0]].push_back({edges[i][1], succProb[i]});
            g[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }

        priority_queue<pair<double, int>> pq;
        pq.push({1.0, start_node});
        vector<double> v(n ,0);

        while(!pq.empty()) {
            auto curr = pq.top();
            pq.pop();

            if(curr.second == end_node) return curr.first;

            for(auto adj : g[curr.second]) {
                if(v[adj.first] < curr.first * adj.second) {
                    v[adj.first] = curr.first * adj.second;
                    pq.push({v[adj.first], adj.first});
                }
            }
        }
        return 0;
    }
};