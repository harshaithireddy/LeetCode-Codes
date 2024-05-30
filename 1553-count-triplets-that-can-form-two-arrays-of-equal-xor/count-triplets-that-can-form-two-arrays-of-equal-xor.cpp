class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        int res = 0;

        vector<int> prefix(n + 1, 0);
        unordered_map<int, int> sumOfi, countOfXor;
        sumOfi[0] = 0;
        countOfXor[0] = 1;

        for(int k = 1; k <= n; k++) {
            prefix[k] = prefix[k - 1] ^ arr[k - 1];
            int x = prefix[k];
            res += k * countOfXor[x] - sumOfi[x] - 1 * countOfXor[x];

            countOfXor[x]++;
            sumOfi[x] += k;
        }
        return res;
    }
};