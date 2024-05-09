class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        sort(happiness.begin(), happiness.end(), greater<int>());

        int dec = 0;
        long long res = 0;
        for(int i = 0; i < k; i++) {
            res += max(0, happiness[i] - dec);
            dec++;
        }
        return res;
    }
};