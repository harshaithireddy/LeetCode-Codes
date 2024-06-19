class Solution {
public:
    bool mBouquets(int mid, vector<int>& bloomDay, int m, int k) {
        int consecutiveCnt = 0;
        int numOfBouquets = 0;
        for(int i = 0; i < bloomDay.size(); i++) {
            if(bloomDay[i] <= mid) consecutiveCnt++;
            else consecutiveCnt = 0;

            if(consecutiveCnt == k) {
                numOfBouquets++;
                consecutiveCnt = 0;
            } 
        }
        return numOfBouquets >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        if((long long)m * k > bloomDay.size()) return -1;
        
        int l = 1; 
        int r = *max_element(bloomDay.begin(), bloomDay.end());
        int res = -1;

        while(l <= r) {
            int mid = (l + r) / 2;
            if(mBouquets(mid, bloomDay, m, k) == true) {
                res = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        return res;
    }
};