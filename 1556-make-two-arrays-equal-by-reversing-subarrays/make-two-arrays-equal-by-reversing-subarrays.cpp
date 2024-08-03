class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> mpp;
        int n = arr.size();

        for(int i = 0; i < n; i++) {
            mpp[target[i]]++;
        }
        for(int i = 0; i < n; i++) {
            if(mpp[arr[i]] >= 1) mpp[arr[i]]--;
            else return false;
        }
        return true;
    }
};