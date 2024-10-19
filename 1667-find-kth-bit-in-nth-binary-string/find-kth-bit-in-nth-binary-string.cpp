class Solution {
public:
    string fun(string s) {
        string x = "";
        for(int j = s.size() - 1; j >= 0; j--) {
            x += s[j] == '0' ? '1' : '0';
        }
        return x;
    }
    
    char findKthBit(int n, int k) {
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        
        if(k == 1) return '0';

        string s = "0";
        for(int i = 1; i < n; i++) {
            s += "1" + fun(s);
            if(s.size() >= k) return s[k - 1];
        }
        return s[k - 1];
    }
};
