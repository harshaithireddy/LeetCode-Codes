class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums[0].size();
        string res = "";
        
        for(int i = 0; i < n; i++) {
            res.push_back(nums[i][i] == '0' ? '1' : '0'); 
        }
        return res;
    }
};