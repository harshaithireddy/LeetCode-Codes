class Solution {
public:
    long long flowerGame(int n, int m) {
        long long cnt = 0;

        int oddsFirst = (n + 1) / 2;
        int evensSecond = m / 2;
        cnt += (1LL * oddsFirst * evensSecond);

        int evensFirst = n / 2;
        int oddsSecond = (m + 1) / 2;
        cnt += (1LL * evensFirst * oddsSecond);

        return cnt;
    }
};