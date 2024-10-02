class Solution {
public:
    int speedup = []{ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0;}();
    
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> temp = arr;
        unordered_map<int, int> mpp;
        sort(temp.begin(), temp.end());

        int i = 0;
        int rank = 1;
        while(i < arr.size()) {
            if(i == 0 || temp[i] == temp[i - 1]) {}
            else rank++;

            mpp[temp[i]] = rank;
            i++;
        }

        for(int i = 0; i < arr.size(); i++) {
            arr[i] = mpp[arr[i]];
        } 
        return arr;
    }
};