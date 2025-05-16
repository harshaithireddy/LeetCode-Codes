class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum = 0, maxi = 0;
        for(int i = 0; i < k; i++) {
            sum += cardPoints[i];
        }
        maxi = sum;
        int last = cardPoints.size() - 1;
        for(int i = k-1; i >= 0; i--) {
            sum -= cardPoints[i];
            sum += cardPoints[last];
            maxi = max(maxi, sum);
            last--;
        }
        return maxi;
    }
};