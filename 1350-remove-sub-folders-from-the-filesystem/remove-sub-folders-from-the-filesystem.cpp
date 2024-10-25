auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());

        vector<string> res;
        res.push_back(folder[0]);
        string temp = folder[0];
        for(int i = 1; i < folder.size(); i++) {
            if(folder[i].find(temp + "/") != 0) {
                res.push_back(folder[i]);
                temp = folder[i];
            }
        }
        return res;
    }
};