class Solution {
public:
    bool solver(vector<int>& q, int n, int x) {
        int stores = 0;
        for(auto it : q) {
            stores += (it + x - 1) / x; // ceil(it / x)
        }
        return stores <= n;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int l = 1;
        int r = *max_element(quantities.begin(), quantities.end());
        int res = 0;
        while(l <= r) {
            int mid = (l + r) / 2;
            if(solver(quantities, n, mid)) {
                res = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        } 
        return res;
    }
};