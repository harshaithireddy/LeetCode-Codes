class Solution {
public:
    bool judgeSquareSum(int c) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        long long b = sqrt(c);
        long long a = 0;

        while(a <= b) {
            long long res = a * a + b * b;
            if(res == c) return true;
            else if(res < c) a++;
            else b--;
        }
        return false;
    }
};