class Solution {
public:
    int numTeams(vector<int>& rating) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int res = 0;
        int n = rating.size();

        for(int i = 1; i < n - 1; i++) {
            int leftSmaller = 0, leftLarger = 0;
            int rightSmaller = 0, rightLarger = 0;

            for(int j = 0; j < i; j++) {
                if(rating[j] < rating[i]) leftSmaller++;
                else if(rating[j] > rating[i]) leftLarger++;
            }

            for(int j = i + 1; j < n; j++) {
                if(rating[j] < rating[i]) rightSmaller++;
                else if(rating[j] > rating[i]) rightLarger++;
            }

            res += leftSmaller * rightLarger + leftLarger * rightSmaller;
        }

        return res;
    }
};
