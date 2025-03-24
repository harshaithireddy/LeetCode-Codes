class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        int res = 0;
        int last = 1;
        for(int i = 0; i < meetings.size(); i++) {
            int s = meetings[i][0], e = meetings[i][1];
            if(s > last) res += (i == 0) ? (s - last) : (s - last - 1);

            last = max(last, e);
        }
        if(days > last) res += (days - last);

        return res;
    }
};