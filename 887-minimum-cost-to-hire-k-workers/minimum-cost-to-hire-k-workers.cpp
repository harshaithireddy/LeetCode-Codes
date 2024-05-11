class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        vector<pair<double, int>> workers; 
        for(int i = 0; i < quality.size(); i++) {
            workers.push_back({(wage[i] * 1.0) / quality[i], quality[i]});
        }
        sort(workers.begin(), workers.end());

        priority_queue<int> pq;
        double quantitySum = 0;
        double res = DBL_MAX;
        for(auto it : workers) {
            double ratio = it.first;
            quantitySum += it.second;
            pq.push(it.second);

            if(pq.size() > k) {
                quantitySum -= pq.top();
                pq.pop();
            }
            if(pq.size() == k) {
                res = min(res, quantitySum * ratio);
            }
        }
        return res;
    }
};