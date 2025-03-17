class Solution {
public:
    string addStrings(string num1, string num2) {
        string s = "";
        int i = num1.size() - 1, j = num2.size() - 1;
        int carry = 0;
        while(i >= 0 && j >= 0) {
            int x = (num1[i] - '0') + (num2[j] - '0') + carry;
            carry = x / 10;
            x = x % 10;
            char d = '0';
            d += x;
            s.push_back(d);
            i--;
            j--;
        }

        while(i >= 0) {
            int x = (num1[i] - '0') + carry;
            carry = x / 10;
            x = x % 10;
            char d = '0';
            d += x;
            s.push_back(d);
            i--;
        }

        while(j >= 0) {
            int x = (num2[j] - '0') + carry;
            carry = x / 10;
            x = x % 10;
            char d = '0';
            d += x;
            s.push_back(d);
            j--;
        }

        if(carry) s.push_back('1');

        reverse(s.begin(), s.end());

        return s;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();