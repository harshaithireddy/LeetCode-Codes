class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int windowSum = 0;
        int zeroSum = 0;
        int maxWindow = 0;

        for(int i = 0; i < customers.size(); i++) {
            if(grumpy[i] == 0) zeroSum += customers[i];
            if(i < minutes) {
                if(grumpy[i] == 1) windowSum += customers[i];
                else windowSum += 0;
            }
            else {
                if(grumpy[i] == 1) {
                    if(grumpy[i - minutes] == 1) windowSum += customers[i] - customers[i - minutes];
                    else windowSum += customers[i];
                }
                else {
                    if(grumpy[i - minutes] == 1) windowSum += 0 - customers[i - minutes];
                    else windowSum += 0;   
                }
            }
            maxWindow = max(maxWindow, windowSum);
        }
        return maxWindow + zeroSum;
    }
};