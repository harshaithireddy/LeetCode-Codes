class Solution {
public:
    string originalDigits(string s) {
        unordered_map<char, int> mpp;
        for(auto it : s) mpp[it]++;

        string res;
        vector<pair<pair<char, char>, string>> v = {{{'z', '0'}, "zero"}, {{'w', '2'}, "two"}, {{'u', '4'}, "four"}, 
                                                    {{'x', '6'}, "six"}, {{'g', '8'}, "eight"}, {{'o', '1'}, "one"}, 
                                                    {{'t', '3'}, "three"}, {{'f', '5'}, "five"}, {{'s', '7'}, "seven"}, 
                                                    {{'i', '9'}, "nine"}};
        for(auto p : v) {
            int n = mpp[p.first.first];
            for(int i = 0; i < n; i++) res += p.first.second;
            for(char c : p.second) mpp[c] -= n;
        }
        sort(res.begin(), res.end());
        return res;
    }
};