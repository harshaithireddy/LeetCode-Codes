class Solution {
public:
    void solver(int n, int i, int sum, bool& res) {
        if(sum == n) {
            res = true;
            return;
        }
        if(sum > n || pow(3, i) > n) {
            return;
        }

        solver(n, i + 1, sum + pow(3, i), res);
        solver(n, i + 1, sum, res);
    }

    bool checkPowersOfThree(int n) {
        bool res = false;
        solver(n, 0, 0, res);
        return res;
    }
};
