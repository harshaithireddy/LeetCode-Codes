class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        ios_base::sync_with_stdio(false);
        queue<int> q;
        for(int i = 0; i < tickets.size(); i++) {
            q.push(i);
        }

        int res = 0;
        while(!q.empty()) {
            res++;

            int x = q.front();
            q.pop();
            tickets[x]--;

            if(k == x && tickets[x] == 0) break;
            if(tickets[x] != 0) q.push(x);
        }
        return res;
    }
};