class Solution {
public:
    double myPow(double x, long long n) {
        if(n == 0) return 1;

        if(n < 0) {
            x = 1 / x;
            n = -n;
        }
        double sub = myPow(x, n/2);
        if(n & 1) return (x * sub * sub);
        return sub * sub;
    }
};