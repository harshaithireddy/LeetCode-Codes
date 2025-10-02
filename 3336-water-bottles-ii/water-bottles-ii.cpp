class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int res = numBottles;
        while(numBottles >= numExchange) {
            numBottles -= numExchange;
            numExchange++;
            res++;
            numBottles++;
        }
        return res;
    }
};