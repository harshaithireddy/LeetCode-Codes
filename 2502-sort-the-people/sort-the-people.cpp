class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        map<int, string> mpp;
        for(int i = 0; i < names.size(); i++) {
            mpp[heights[i]] = names[i];
        }

        vector<string> V;
        for(auto it : mpp) {
            V.push_back(it.second);
        }
        reverse(V.begin(), V.end());
        return V;
    }
};