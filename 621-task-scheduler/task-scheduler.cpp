class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> mpp;
        for(auto it : tasks) {
            mpp[it]++;
        }
        
        priority_queue<int> pq;
        for(auto it : mpp) {
            pq.push(it.second);
        }

        int res = 0;

        while(!pq.empty()) {
            int time = 0;
            vector<int> temp;
            for(int i = 0; i < n+1; i++) {
                if(!pq.empty()) {
                    temp.push_back(pq.top() - 1);
                    time++;
                    pq.pop();
                }
            }
            for(auto i : temp) {
                if(i > 0) pq.push(i);
            }
            if(pq.empty()) res += time;
            else res += (n + 1);
        }
        return res;
    }
};