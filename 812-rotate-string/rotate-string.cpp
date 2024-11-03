class Solution {
public:
    bool rotateString(string s, string goal) {
        for(int i = 0; i < s.size(); i++) {
            char x = s.front();
            s.erase(0, 1);
            s.push_back(x);
            if(s == goal) return true;
        }
        return false;
    }
};