class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string s = to_string(num);
        int i = 0;
        int j = k - 1;

        int cnt = 0;
        while (j < s.size()) {
            string str = s.substr(i, k);
            if(stoi(str) != 0 && num % stoi(str) == 0) {
                cnt++;
            }
            i++;
            j++;
        }
        return cnt;
    }
};