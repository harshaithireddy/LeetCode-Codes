class Solution {
public:
    bool generate(vector<int>& V, vector<bool>& used, int ind, int n) {
        if(ind == V.size()) return true;

        if(V[ind] != 0) return generate(V, used, ind + 1, n);

        for(int i = n; i >= 1; i--) {
            int nextInd = (i == 1) ? ind : ind + i;
            if(used[i] || (i > 1 && (nextInd >= V.size() || V[nextInd] != 0))) continue;

            V[ind] = V[nextInd] = i;
            used[i] = true;

            if(generate(V, used, ind + 1, n)) return true;

            V[ind] = V[nextInd] = 0;
            used[i] = false;
        }
        return false;
    }

    
    vector<int> constructDistancedSequence(int n) {
        vector<int> V(2*n - 1, 0);
        vector<bool> used(n + 1, false);
        generate(V, used, 0, n);

        return V;
    }
};