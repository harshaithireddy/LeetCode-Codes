class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int maxi = 1, res = 0, n = colors.size();

        for(int i = 1; i <= n-1+k-1; i++) {
            if(colors[i % n] != colors[(i-1+n) % n]) maxi++;
            else maxi = 1;

            if(maxi >= k) res++;
        }
        return res;
    }
};