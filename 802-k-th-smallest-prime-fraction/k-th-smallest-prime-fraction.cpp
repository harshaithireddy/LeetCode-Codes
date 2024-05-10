class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        vector<pair<double, pair<int, int>>> V;
        int n = arr.size();

        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                V.push_back({static_cast<double>(arr[i]) / arr[j], {i, j}});
            }
        }

        sort(V.begin(), V.end());

        int first = arr[V[k - 1].second.first];
        int second = arr[V[k - 1].second.second];

        return {first, second};
    }
};