class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        unordered_map<int, int> mpp;
        for(int i = 0; i < arr.size(); i++) {
            mpp[arr[i]] = i + 1;
        }

        int largest = arr.size();
        int i = 0;
        vector<int> ans;
        while(i < arr.size()) {
            if(mpp.find(largest) != mpp.end()) {
                ans.push_back(mpp[largest]);
                ans.push_back(largest);
                reverse(arr.begin(), arr.begin() + mpp[largest]);
                reverse(arr.begin(), arr.begin() + largest);
            }
            mpp.clear();
            for(int i = 0; i < arr.size(); i++) {
                mpp[arr[i]] = i + 1;
            }
            largest--;
            i++;
        }
        return ans;
    }
};