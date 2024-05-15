class Solution {
public:
    void bfs(vector<vector<int>>& grid, vector<vector<int>>& V) {
        int n = grid.size();
        vector<int> row = {0,0,-1,1};
        vector<int> col = {-1,1,0,0};

        queue<pair<int, int>> q;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    V[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        while(!q.empty()) {
            auto temp = q.front();
            q.pop();

            int r = temp.first, c = temp.second;
            int x = V[r][c];
            for(int i = 0; i < 4; i++) {
                int newr = r + row[i];
                int newc = c + col[i];

                if(newr >= 0 && newr < n && newc >= 0 && newc < n && V[newr][newc] > 1 + x) {
                    V[newr][newc] = 1 + x;
                    q.push({newr, newc});
                }
            }
        }
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> row = {0,0,-1,1};
        vector<int> col = {-1,1,0,0};

        vector<vector<int>> V(n, vector<int>(n, INT_MAX));
        bfs(grid, V);
        vector<vector<bool>> vis(n, vector<bool>(n, false));

        priority_queue<pair<int, pair<int, int>>> pq;
        pq.push({V[0][0], {0, 0}});
        while(!pq.empty()) {
            auto x = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();

            if(r == n-1 && c == n-1) return x;
            vis[r][c] = true;

            for(int i = 0; i < 4; i++) {
                int newr = r + row[i];
                int newc = c + col[i];

                if(newr >= 0 && newr < n && newc >= 0 && newc < n && !vis[newr][newc]) {
                    int res = min(x, V[newr][newc]);
                    pq.push({res, {newr, newc}});
                    vis[newr][newc] = true;
                }
            }
        }
        return -1;
    }
};