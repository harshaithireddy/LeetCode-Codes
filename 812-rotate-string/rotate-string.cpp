class Solution {
public:
    bool rotateString(string s, string goal) {
        string temp = s;
        for(int i = 0; i < temp.size(); i++) {
            char x = temp.front();
            temp.erase(0, 1);
            temp.push_back(x);
            if(temp == goal) return true;
        }
        return false;
    }
};