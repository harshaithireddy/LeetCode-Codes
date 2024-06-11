class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        vector<int> V(1001, 0);
        for(auto it : arr1) {
            V[it]++;
        }
        vector<int> res;
        for(int i = 0; i < arr2.size(); i++) {
            while(V[arr2[i]]--) res.push_back(arr2[i]);
        }

        for(int i = 0; i <= 1000; i++) {
            int x = V[i];
            while(x > 0) {
                res.push_back(i);
                x--;
            }
        }
        return res;
    }
};