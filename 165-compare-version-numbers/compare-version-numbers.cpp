class Solution {
public:
    int compareVersion(string version1, string version2) {
        int m = version1.size();
        int n = version2.size();
        for(int i = 0, j = 0; (i < m) || (j < n); i++, j++) {
            int val1 = 0, val2 = 0;
            while((i < m) && (version1[i] != '.')) {
                val1 = val1 * 10 + (version1[i++] - '0');
            }
            while((j < n) && (version2[j] != '.')) {
                val2 = val2 * 10 + (version2[j++] - '0');
            }
            if(val1 < val2) return -1;
            if(val1 > val2) return 1;
        }
        return 0;
    }
};