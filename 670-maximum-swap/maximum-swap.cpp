class Solution {
public:
    int maximumSwap(int num) {
        string num1 = to_string(num);
        int n = num1.size();

        vector<int> maxIdx(n);
        maxIdx[n - 1] = n - 1;
        for(int i = n - 2; i >= 0; i--) {
            if(num1[i] > num1[maxIdx[i + 1]]) maxIdx[i] = i;
            else maxIdx[i] = maxIdx[i + 1];
        }

        for(int i = 0; i < n; i++) {
            if(num1[i] < num1[maxIdx[i]]) {
                swap(num1[i], num1[maxIdx[i]]);
                break;
            }
        }
        return stoi(num1);
    }
};
