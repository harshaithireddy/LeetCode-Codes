class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_map<char, int> mpp;

        for(int i = 0; i < allowed.size(); i++) mpp[allowed[i]]++;

        int cnt = 0;
        for(int i = 0; i < words.size(); i++) {
            bool flag = true; 
            for(auto it : words[i]) {
                if(mpp.find(it) == mpp.end()) {
                    flag = false;
                    break;
                }
            }
            if(flag == true) cnt++;
        }
        return cnt;
    }
};