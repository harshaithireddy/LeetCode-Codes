class Solution {
private:
    bool checkEqualFrequency(string word) {
        unordered_map<char, int> freqMap;
        for(char ch : word) {
            freqMap[ch]++;
        }

        int target = -1;

        for(auto it : freqMap) {
            if(target == -1) {
                target = it.second;
            }
            else if(it.second != target) {
                return false;
            }
        }

        return true;
    }

public:
    bool equalFrequency(string word) {
        for (int i = 0; i < word.length(); ++i) {
            string temp = word;
            temp.erase(i, 1);
            if(checkEqualFrequency(temp)) {
                return true;
            }
        }
        return false;
    }
};