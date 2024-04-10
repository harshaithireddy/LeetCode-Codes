class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        queue<int> q;
        int n = deck.size();
        sort(deck.begin(), deck.end());
        
        for(int i = 0; i < n; i++) q.push(i);
        vector<int> res(n);

        for(int i = 0; i < n; i++) {
            res[q.front()] = deck[i];
            q.pop();

            if(!q.empty()) {
                q.push(q.front());
                q.pop();
            }
        }
        return res;
    }
};