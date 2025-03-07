class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<int> prime(right + 1, 1);
        prime[0] = 0, prime[1] = 0;

        for(int i = 2; i * i <= right; i++) {
            for(int j = i * i; j <= right; j += i) {
                prime[j] = 0;
            }
        }

        vector<int> V;
        for(int i = left; i <= right; i++) {
            if(prime[i]) V.push_back(i);
        }

        if(V.size() < 2) return {-1, -1};

        int mini = INT_MAX;
        vector<int> res(2, -1);
        for(int i = 1; i < V.size(); i++) {
            if(V[i] - V[i-1] < mini) {
                mini = V[i] - V[i-1];
                res[0] = V[i-1];
                res[1] = V[i];
            }
        }
        return res;
    }
};