class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        return numBottles + (numBottles - 1) / (numExchange - 1);
    }
};