class Solution {
public:
    int pivotInteger(int n) {
        long long sum1 = (n * (n + 1) / 2);
        int sum2 = 0;
        for(int i = 1; i <= n; i++) {
            sum2 += i;
            if(sum1 + i - sum2 == sum2) return i;
            if(sum1 + i - sum2 < 0) break;
        }
        return -1;
    }
};