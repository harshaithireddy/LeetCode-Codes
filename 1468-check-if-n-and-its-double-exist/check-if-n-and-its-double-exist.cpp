class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int, int> mpp;
        for(int i = 0; i < arr.size(); i++) {
            if(mpp.find(arr[i] * 2) != mpp.end()) return true;
            else if(arr[i] % 2 == 0 && mpp.find(arr[i] / 2) != mpp.end()) return true;
            
            mpp[arr[i]]++;
        }
        return false;
    }
};