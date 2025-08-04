class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int start = 0;
        int maxi = 0;
        unordered_map<int, int> mpp;

        for(int end = 0; end < fruits.size(); end++) {
            mpp[fruits[end]]++;

            while(mpp.size() > 2) {
                mpp[fruits[start]]--;
                if(mpp[fruits[start]] == 0) {
                    mpp.erase(fruits[start]);
                }
                start++;
            }

            maxi = max(maxi, end - start + 1);
        }

        return maxi;
    }
};