class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> V(k, 0);

        for(int i = 0; i < arr.size(); i++) {
            int rem = ((arr[i] % k) + k) % k;
            V[rem]++;
        }

        if(V[0] % 2 != 0) return false;
        for(int i = 1; i < k; i++) {
            if(V[i] != V[k - i]) return false;
        }
        return true;
    }
};