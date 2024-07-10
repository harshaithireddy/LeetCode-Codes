class Solution {
public:
    int minOperations(vector<string>& logs) {
        int res = 0;
        for(auto it : logs) {
            if(res == 0 && it == "../" || it == "./") continue;
            else if(it == "../" && res != 0) res--;
            else res++;
        }
        return res;
    }
};