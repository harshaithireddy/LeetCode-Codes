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
            s = to_string(x) + s;
            i--;
            j--;
        }

        while(i >= 0) {
            int x = (num1[i] - '0') + carry;
            carry = x / 10;
            x = x % 10;
            s = to_string(x) + s;
            i--;
        }

        while(j >= 0) {
            int x = (num2[j] - '0') + carry;
            carry = x / 10;
            x = x % 10;
            s = to_string(x) + s;
            j--;
        }

        if(carry) s = '1' + s;

        return s;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();