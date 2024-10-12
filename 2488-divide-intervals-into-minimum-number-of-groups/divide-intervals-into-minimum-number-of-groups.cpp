auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c++';
}();

class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        vector<int> start, end;
        int n = intervals.size();
        for(int i = 0; i < n; i++) {
            start.push_back(intervals[i][0]);
            end.push_back(intervals[i][1]);   
        }
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        int j = 0;
        int res = 0;
        for(int i = 0; i < n; i++) {
            if(start[i] > end[j]) j++;
            else res++;
        }
        return res;
    }
};