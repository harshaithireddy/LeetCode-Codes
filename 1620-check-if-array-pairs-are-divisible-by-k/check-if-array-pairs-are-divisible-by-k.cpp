class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int, int> mpp;

        for(int i = 0; i < arr.size(); i++) {
            int rem = ((arr[i] % k) + k) % k;
            mpp[rem]++;
        }

        if(mpp[0] % 2 != 0) return false;
        for(int i = 1; i < k; i++) {
            if(mpp[i] != mpp[k - i]) return false;
        }
        return true;
    }
};