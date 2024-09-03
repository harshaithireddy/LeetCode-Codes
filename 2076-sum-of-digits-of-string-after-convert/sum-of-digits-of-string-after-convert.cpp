class Solution {
public:
    int getLucky(string s, int k) {
        string num = "";
        for(char c : s) {
            num += to_string(c - 'a' + 1);
        }

        while(k--) {
            int sum = 0;
            for(int i = 0; i < num.size(); i++) {
                sum += num[i] - '0';
            }
            num = to_string(sum);
        }
        return stoi(num);
    }
};