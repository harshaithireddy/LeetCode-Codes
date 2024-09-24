class Solution {
public:
    int speedup = []{ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0;}();
    
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        if(arr2.size() > arr1.size()) {
            swap(arr1, arr2);
        }
        unordered_set<int> st;
        for(int i = 0; i < arr2.size(); i++) {
            int n = arr2[i];
            while(n > 0 && st.find(n) == st.end()) {
                st.insert(n);
                n /= 10;
            }
        }

        int res = 0;
        for(int i = 0; i < arr1.size(); i++) {
            int n = arr1[i];
            while(n > 0 && st.find(n) == st.end()) n /= 10;

            if(n != 0) {
                int len = to_string(n).length();
                res = max(res, len);
            }
        }
        return res;
    }
};