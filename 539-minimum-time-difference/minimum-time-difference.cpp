class Solution {
public:
    int speedup = []{ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0;}();
    
    int convertToMinutes(string time) {
        return stoi(time.substr(0, 2)) * 60 + stoi(time.substr(3, 2));
    }

    int findMinDifference(vector<string>& timePoints) {
        sort(timePoints.begin(), timePoints.end());
        timePoints.push_back(timePoints[0]);

        int res = INT_MAX;
        int n = timePoints.size();
        for(int i = 0; i < n - 1; i++) {
            int time_one = convertToMinutes(timePoints[i]);
            int time_two = convertToMinutes(timePoints[i + 1]);
            int diff = abs(time_one - time_two);
            res = min(res, min(diff, 1440 - diff));
        }
        return res;
    }
};
