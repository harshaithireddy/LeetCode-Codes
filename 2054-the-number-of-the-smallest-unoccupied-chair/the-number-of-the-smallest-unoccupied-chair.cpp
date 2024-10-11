auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c++';
}();

class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();

        vector<pair<pair<int, int>, int>> events;
        for(int i = 0; i < n; i++) {
            events.push_back({{times[i][0], 1}, i});
            events.push_back({{times[i][1], -1}, i});
        }

        sort(events.begin(), events.end());

        vector<int> chairs(n, -1);

        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i = 0; i < n; i++) pq.push(i);

        for(auto event : events) {
            int time = event.first.first;
            int type = event.first.second;
            int person = event.second;

            if(person == targetFriend && type == 1) return pq.top();

            if(type == 1) {
                chairs[person] = pq.top();
                pq.pop();
            }
            else {
                pq.push(chairs[person]);
                chairs[person] = -1;
            }
        }
        return -1;
    }
};