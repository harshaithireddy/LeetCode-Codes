class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        vector<int> temp(n, 0);
        int res = INT_MIN;

        for(int i = n-1; i >= 0; i--) {
            if(i + k < n) temp[i] = energy[i] + temp[i + k];
            else temp[i] = energy[i];
            
            res = max(res, temp[i]);
        }
        return res;
    }
};