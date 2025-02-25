class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int MOD = 1e9 + 7;
        int odd = 0, even = 1;
        int prefix = 0;

        int res = 0;

        for(int i = 0; i < arr.size(); i++) {
            prefix += arr[i];

            if(prefix % 2 == 1) {
                res = (res + even) % MOD;
                odd++;
            }
            else {
                res = (res + odd) % MOD;
                even++;
            }
        }
        return res;
    }
};