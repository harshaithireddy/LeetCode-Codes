class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        ios_base::sync_with_stdio(false);
        uint32_t res = 0;
        int i = 31;

        while(n) {
            res += pow(2, i) * (n & 1);
            i--;
            n >>= 1;
        }
        return res;
    }
};