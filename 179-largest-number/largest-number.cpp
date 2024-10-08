class Solution {
public:
    int speedup = []{ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0;}();
    
    static bool comp(int a, int b) {
        string strA = to_string(a);
        string strB = to_string(b);
        return strA + strB > strB + strA;
    }

    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), comp);

        string res = "";
        for(auto s : nums) {
            res += to_string(s);
        }

        while(res.size() > 1 && res[0] == '0') {
            res.erase(0, 1);
        }
        return res;
    }
};