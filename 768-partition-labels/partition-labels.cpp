class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> mpp;
        for(int i = 0; i < s.size(); i++) {
            mpp[s[i]] = i;
        }

        int first = 0;
        int last = mpp[s[0]];

        vector<int> V;
        for(int i = 0; i < s.size(); i++) {
            if(i == last) {
                V.push_back(last - first + 1);
                first = last + 1;
                last = mpp[s[first]];
            }
            else {
                last = max(last, mpp[s[i]]);
            }
        }
        return V;
    }
};