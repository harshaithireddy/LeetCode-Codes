class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        stack<int> s;
        int n = t.size();
        vector<int> V(n, 0);
        s.push(n-1);
        for(int i = n-2; i >= 0; i--) {
            while(!s.empty() && t[s.top()] <= t[i]) {
                V[i] = 1;
                s.pop();
            }
            if(!s.empty()) {
                int x = abs(s.top() - i);
                V[i] = x;
            }
            else V[i] = 0;
            s.push(i);
        }
        return V;
    }
};