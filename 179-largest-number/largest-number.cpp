class Solution {
public:
    static bool comp(string a, string b) {
        return a + b > b + a;
    }
    string largestNumber(vector<int>& nums) {
        vector<string> numString;
        for(auto it : nums) {
            numString.push_back(to_string(it));
        }

        sort(numString.begin(), numString.end(), comp);

        string res = "";
        for(auto s : numString) {
            res += s;
        }
        
        while(res.size() > 1 && res[0] == '0') {
            res.erase(0, 1);
        }
        return res;
    }
};