class Solution {
public:
    string frequencySort(string s) {
        map<char, int> mpp;
        for(int i = 0; i < s.size(); i++) {
            mpp[s[i]]++;
        }
        vector<pair<char, int>> vec(mpp.begin(), mpp.end());

        sort(vec.begin(), vec.end(), [](auto a, auto b) {
            return a.second > b.second;
        });

        string res;
        for(auto it : vec) {
            for(int i = 0; i < it.second; i++) {
                res += it.first;
            }
        }
        return res;
    }
};












