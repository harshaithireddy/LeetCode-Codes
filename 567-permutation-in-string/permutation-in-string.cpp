class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();

        if(n1 > n2) return false;

        vector<int> x(26, 0);
        vector<int> y(26, 0);

        for(int i = 0; i < n1; i++) x[s1[i] - 'a']++;
        for(int i = 0; i < n1; i++) y[s2[i] - 'a']++;

        for(int i = 0; i < n2 - n1; i++) {
            if(x == y) return true;
            y[s2[i] - 'a']--;
            y[s2[i + n1] - 'a']++;
        }
        if(x == y) return true;
        return false;
    }
};