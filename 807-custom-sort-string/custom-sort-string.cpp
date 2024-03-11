class Solution {
public:
    string customSortString(string order, string s) {
        map<char, int> mpp;
        for(char ch : s) {
            mpp[ch]++;
        }
        string res = "";
        for(char c : order) {
            if(mpp.find(c) != mpp.end() || mpp[c] >= 1) {
                while(mpp[c]--)
                res += c;
                //mpp[c]--;
            }
        }
        for(auto& it : mpp) {
            while(it.second > 0) {
                res += it.first;
                mpp[it.first]--;
            }
        }
        return res;
    }
};