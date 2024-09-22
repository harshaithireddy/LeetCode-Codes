class Solution {
public:
    long long count(long long curr, int n) {
        long long res = 0;
        long long nei = curr + 1;
        while(curr <= n) {
            res += min(nei, (long long)(n + 1)) - curr;
            curr *= 10;
            nei *= 10;
        }
        return res;
    }
    
    int findKthNumber(int n, int k) {
        long long curr = 1;
        int i = 1;

        while(i < k) {
            long long steps = count(curr, n);
            if(i + steps <= k) {
                curr += 1;
                i += steps;
            }
            else {
                curr *= 10;
                i += 1;
            }
        }
        return curr;
    }
};
