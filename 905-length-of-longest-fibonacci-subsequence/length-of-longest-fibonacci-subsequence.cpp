class Solution {
public:
    int longest = 2;
    unordered_map<int, int> mpp;

    void solver(int i, int j, vector<int>& arr, int cnt) {
        if(cnt > longest) longest = cnt;
        if(j > arr.size()) return;

        if(mpp.find(arr[i] + arr[j]) != mpp.end()) {
            int k = mpp[arr[i] + arr[j]];
            solver(j, k, arr, cnt + 1);
        }
    }

    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();

        for(int i = 0; i < n; i++) mpp[arr[i]] = i;
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                solver(i, j, arr, 2);
            }
        }
        return longest > 2 ? longest : 0;
    }
};