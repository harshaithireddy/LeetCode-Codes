class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        for(int k = 1; k <= 60; k++) {
            long long s = (long long)num1 - (long long)k * num2;
            if(s <= 0) continue;
            if(__builtin_popcountll(s) <= k && s >= k) return k;
        }
        return -1;
    }
};