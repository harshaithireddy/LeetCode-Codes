class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> cnt(101, 0);
        for(auto it : heights) {
            cnt[it]++;
        }

        int res = 0;
        int x = 0;
        for(int i = 0; i < heights.size(); i++) {
            while(cnt[x] == 0) x++;

            if(heights[i] == x) cnt[x]--;
            else {
                res++;
                cnt[x]--;
            }
        }
        return res;
    }
};