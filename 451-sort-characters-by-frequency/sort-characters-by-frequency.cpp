class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mpp;
        for(int i = 0; i < s.size(); i++) {
            mpp[s[i]]++;
        }

        multimap<int, char, greater<int>> m;
        for(auto it : mpp) {
            m.insert({it.second, it.first});
        }

        string res;
        for(auto it : m) {
            for(int i = 0; i < it.first; i++) {
                res += it.second;
            }
        }
        return res;
    }
};