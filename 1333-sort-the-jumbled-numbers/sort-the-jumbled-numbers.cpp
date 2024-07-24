class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int, int>> pairs;
        for(int i = 0; i < nums.size(); i++) {
            string x = to_string(nums[i]);
            int n = 0;
            for(char it : x) {
                n = n * 10 + mapping[it - '0'];
            }
            pairs.push_back({n, i});
        }
        sort(pairs.begin(), pairs.end());
        vector<int> res;
        for(auto it : pairs) {
            res.push_back(nums[it.second]);
        }
        return res;
    }
};