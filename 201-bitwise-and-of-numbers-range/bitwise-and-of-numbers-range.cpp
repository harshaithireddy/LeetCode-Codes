class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int n = 0;
        while(left != right) {
            left >>= 1;
            right >>= 1;
            n++;
        }
        return left << n;
    }
};