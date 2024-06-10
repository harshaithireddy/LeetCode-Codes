class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> V(heights);
        sort(V.begin(), V.end());

        int res = 0;
        for(int i = 0; i < heights.size(); i++) {
            if(V[i] != heights[i]) res++;
        }
        return res;
    }
};