class Solution {
public:
    bool possible(int mid, vector<int>& position, int m) {
        int ballsPlaced = 1;
        int prev = 0;
        for(int i = 1; i < position.size(); i++) {
            if(position[i] - position[prev] >= mid) {
                ballsPlaced++;
                prev = i;
            }
        }
        return ballsPlaced >= m;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        
        int l = 1;
        int r = *max_element(position.begin(), position.end());

        int res = -1;
        while(l <= r) {
            int mid = (l + r) / 2;
            if(possible(mid, position, m) == true) {
                res = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }
        return res;
    }
};