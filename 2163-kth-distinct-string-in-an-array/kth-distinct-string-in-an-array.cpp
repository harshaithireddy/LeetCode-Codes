class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        unordered_map<string, int> mpp;
        for(int i = 0; i < arr.size(); i++) {
            mpp[arr[i]]++;
        }

        for(int i = 0; i < arr.size(); i++) {
            if(mpp[arr[i]] == 1) k-= 1;

            if(k == 0) return arr[i];
        }
        return "";
    }
};