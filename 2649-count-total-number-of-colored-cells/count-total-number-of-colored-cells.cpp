class Solution {
public:
    long long coloredCells(int n) {
        long long res = 1;
        for(int i = 1; i < n; i++) res += 4 * i;

        return res;
    }
};