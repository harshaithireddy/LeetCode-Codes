class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.empty()) return 0;
        sort(points.begin(), points.end());
        int i = 0;
        int n = points.size();

        int cnt = 1;
        int x = points[0][1];

        while(i < n) {
            if(points[i][0] <= x) {
                x = min(x, points[i][1]);
                i++;
            }
            else {
                x = points[i][1];
                i++;
                cnt++;
            }
        }
        return cnt;
    }
};