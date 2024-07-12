class Solution {
public:
    int maximumGain(string s, int x, int y) {
        string str = "";
        int res = 0;

        if(x > y) {
            for(auto it : s) {
                if(!str.empty() && it == 'b' && str.back() == 'a') {
                    res += x;
                    str.pop_back();
                }
                else str.push_back(it);
            }
            s = str;
            str = "";
            for(auto it : s) {
                if(!str.empty() && it == 'a' && str.back() == 'b') {
                    res += y;
                    str.pop_back();
                }
                else str.push_back(it);
            }
        }
        else {
            for(auto it : s) {
                if(!str.empty() && it == 'a' && str.back() == 'b') {
                    res += y;
                    str.pop_back();
                }
                else str.push_back(it);
            }
            s = str;
            str = "";
            for(auto it : s) {
                if(!str.empty() && it == 'b' && str.back() == 'a') {
                    res += x;
                    str.pop_back();
                }
                else str.push_back(it);
            }
        }
        return res;
    }
};