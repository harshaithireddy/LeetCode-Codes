class Solution {
public:
    unordered_map<int, int> mpp;
    int helper(int i, vector<vector<int>>& books, int shelfWidth) {
        if(i == books.size()) return 0;

        if(mpp.find(i) != mpp.end()) return mpp[i];

        int currWidth = shelfWidth;
        int maxHeight = 0;
        mpp[i] = INT_MAX;

        for(int j = i; j < books.size(); j++) {
            int width = books[j][0];
            int height = books[j][1];

            if(currWidth < width) break;

            currWidth -= width;
            maxHeight = max(maxHeight, height);

            mpp[i] = min(mpp[i], helper(j + 1, books, shelfWidth) + maxHeight);
        }
        return mpp[i];
    }
    
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        return helper(0, books, shelfWidth);
    }
};