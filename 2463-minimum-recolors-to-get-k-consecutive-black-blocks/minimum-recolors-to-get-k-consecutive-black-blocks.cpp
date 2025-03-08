class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int w = 0, b = 0;
        for(int i = 0; i < k; i++) {
            if(blocks[i] == 'W') w++;
            else b++;
        }
        if(b == k) return 0;

        int res = w;
        int n = blocks.size();
        for(int i = k; i < n; i++) {
            if(blocks[i] == 'W') w++;
            if(blocks[i] == 'B') b++;

            if(blocks[i-k] == 'W') w--;
            if(blocks[i-k] == 'B') b--;

            res = min(res, w);
        }
        return res;
    }
};