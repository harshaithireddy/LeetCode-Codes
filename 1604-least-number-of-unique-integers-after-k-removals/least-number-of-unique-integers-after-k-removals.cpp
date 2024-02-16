class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        map<int, int> mpp;
        for(int i = 0; i < arr.size(); i++) {
            mpp[arr[i]]++;
        }
        
        vector<pair<int, int>> V;
        for(auto it : mpp) {
            V.push_back({it.second, it.first});
        }

        sort(V.begin(), V.end());
        for(auto &it : V) {
            while(k > 0 && it.first > 0) {
                it.first--;
                k--;
            }
            if(k == 0) break;
        }

        int cnt = 0;
        for(auto it : V) {
            if(it.first > 0) cnt += 1;
        }

        return cnt;
    }
};
